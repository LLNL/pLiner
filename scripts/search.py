import json
import sys
import subprocess
import os
import argparse

from loopst import *
import fglobal
from transform import *

def prRed(skk): print("\033[91m {}\033[00m" .format(skk)) 
def prGreen(skk): print("\033[92m {}\033[00m" .format(skk)) 
def prYellow(skk): print("\033[93m {}\033[00m" .format(skk)) 
def prLightPurple(skk): print("\033[94m {}\033[00m" .format(skk)) 
def prPurple(skk): print("\033[95m {}\033[00m" .format(skk)) 
def prCyan(skk): print("\033[96m {}\033[00m" .format(skk)) 
def prLightGray(skk): print("\033[97m {}\033[00m" .format(skk)) 
def prBlack(skk): print("\033[98m {}\033[00m" .format(skk)) 

def bisection(tranregs, f, typestr):
  llist = tranregs[f]
  size = len(llist)
  if size<=1:
    return llist
  
  run = looprun if typestr=="LOOP" else bbrun
  nllist = llist[::]
  while size>1:
    half = size/2
    left, right = nllist[:half], nllist[half:]
    tranregs[f] = left
    if run(tranregs, typestr):
      nllist, size = left, len(left)
      continue
    tranregs[f] = right
    if run(tranregs, typestr):
      nllist, size = right, len(right)
      continue
    return nllist

  return nllist

def searchfuncs(flist):
  prPurple("\n\nSearch for functions:")

  # step 1: translate all funcs
  trans, comp, exect, const = funcrun(flist) 
  if not trans or not comp or not exect:
    _flist = []
    for func in flist:
      _trans, _comp, _exect, _const = funcrun([func])
      if _trans and _comp and _exect:
        _flist.append(func)
    perc=len(_flist)*100.0/len(flist)
    print perc, "% (", len(_flist), " out of ", len(flist), " functions) can be handled in pLiner.\n"
    flist = _flist[::]
    trans, comp, exect, const = funcrun(flist) 

  if not const:
    prRed("transforming all buggy functions does not fix the bug")
    return False, flist

  # step 2: perform bisection search over the funcs
  _flist = flist[::]
  size=len(_flist)
  while size>1:
    half = size/2
    left, right = _flist[:half], _flist[half:]
    ltrans, lcomp, lexect, lconst = funcrun(left) 
    if lconst:
      _flist, size = left, len(left)
      continue
    rtrans, rcomp, rexect, rconst = funcrun(right) 
    if rconst:
      _flist, size = right, len(right)
      continue
    break

  return True, _flist

def searchloops(rawloops):
  #return True, [[92, 190]]

  prPurple("\n\nSearch for loops:")

  # step 1: translate the outermost loops   
  tranloops={}
  for func in rawloops.keys():
    _loops = rawloops[func]
    _toploops = splitloops(_loops)
    tranloops[func] = _toploops

  ret = {}
  if not looprun(tranloops):
    prRed("transforming for loops does not fix the bug")
    for f in tranloops.keys():
      ret[f]=[] 
      for l in tranloops[f]:
        lstart, lend = l.getLoop()
        ret[f].append([lstart, lend]) 
    return False, ret

  # step 2: perform bisection search over the outermost loops of each function
  for f in tranloops.keys():
    _loops = bisection(tranloops, f, "LOOP")
    tranloops[f] = _loops

  # step 3: when only one loop is error-prone, splict it and seach over its inner loops
    
  for f in tranloops.keys():
    nllist = tranloops[f]
    size = len(nllist)
    while size==1:
      ins = nllist[0].getInnerLoops()
      if len(ins)==0:
        break
      toploops = splitloops(ins)
      tranloops[f] = toploops
      if looprun(tranloops):
        nllist = bisection(tranloops, f, "LOOP")
        size = len(nllist)
      else:
        break
    tranloops[f] = nllist
 
  # return the isolated loops 
  for f in tranloops.keys():
    ret[f] = []
    for l in tranloops[f]:
      lstart, lend = l.getLoop()
      ret[f].append([lstart, lend]) 

  return True, ret 

def searchbbs(bbs):
  #return True, [[130, 132]]
  prPurple("\n\nSearch for bbs:")
  # step 1: translate all bbs   
  if not bbrun(bbs):
    prRed("transforming all buggy bbs does not fix the bug")
    return False, bbs

  # step 2: perform bisection search over the bbs of each function
  for f in bbs.keys():
    _bbs = bisection(bbs, f, "BB")
    bbs[f]=_bbs

  return True, bbs

def searchlines(lines):
  prPurple("\n\nSearch for lines:")
  # step 1: translate all lines   
  if not bbrun(lines, "LINE"):
    prRed("transforming all buggy lines does not fix the bug")
    return False, lines

  # step 2: perform bisection search over the lines of each function
  for f in lines.keys():
    _lines = bisection(lines, f, "LINE")
    lines[f]=_lines

  return True, lines

def print_and_exit(nlist):
  ## print bug area 
  print "\n\n Bug area:"
  for f in nlist.keys():
    for bstart, bend in nlist[f]:
      print f, ":"
      if bstart != bend:
        print "  ", bstart, "->", bend 
      else:
        print "  line ", bstart 

  #global fglobal.codefile, fglobal.funclist, fglobal.compileops, fglobal.logfile, fglobal.verbose
  filesplits = fglobal.codefile.split(".")

  ## generate final region log file
  fout = open(filesplits[0]+"-regions.json", "w")
  json.dump({"pLiner-funcs": fglobal.funclist, "pLiner-fregions": nlist}, fout, sort_keys=True, indent=2, separators=(',', ': '))
  fout.close()
  fglobal.logfile.close()

  ## generate final transformated program
  outfile=filesplits[0]+"_trans."+filesplits[1]
  subprocess.call(['rm',  '-f', outfile])

  status, out, err ="null", "null", "null"
  cmd = "pLiner "+fglobal.codefile+" -r="+filesplits[0]+"-regions.json -o="+outfile+" "+fglobal.compileops 
  FNULL = open(os.devnull, 'w')
  if fglobal.verbose==1:  
    subprocess.call(cmd.split(' '))
  else:
    subprocess.call(cmd.split(' '), stdout=FNULL, stderr=subprocess.STDOUT)

  ## save log file
  cmd = "mv log.txt "+filesplits[0]+"-log.txt"
  subprocess.call(cmd.split(' '))
  
  return outfile, filesplits[0]+"-regions.json", filesplits[0]+"-log.txt"

def print_and_exit_whole(flist):
  ## print bug area 
  print "\n\n Bug area:"
  print flist

  #global fglobal.codefile, fglobal.funclist, fglobal.compileops, fglobal.logfile, fglobal.verbose
  filesplits = fglobal.codefile.split(".")

  ## generate final region log file
  fout = open(filesplits[0]+"-regions.json", "w")
  json.dump({"pLiner-funcs": flist}, fout, sort_keys=True, indent=2, separators=(',', ': '))
  fout.close()
  fglobal.logfile.close()

  ## generate final transformated program
  outfile=filesplits[0]+"_trans."+filesplits[1]
  subprocess.call(['rm',  '-f', outfile])

  status, out, err ="null", "null", "null"
  cmd = "pLiner "+fglobal.codefile+" -r="+filesplits[0]+"-regions.json --whole -o="+outfile+" "+fglobal.compileops 
  FNULL = open(os.devnull, 'w')
  if fglobal.verbose==1:  
    subprocess.call(cmd.split(' '))
  else:
    subprocess.call(cmd.split(' '), stdout=FNULL, stderr=subprocess.STDOUT)

  ## save log file
  cmd = "mv log.txt "+filesplits[0]+"-log.txt"
  subprocess.call(cmd.split(' '))
  
  return outfile, filesplits[0]+"-regions.json", filesplits[0]+"-log.txt"


def clean_and_exit():
  #global fglobal.codefile
  ## remove TEST_trans.c
  filesplits = fglobal.codefile.split(".")
  outs=filesplits[0]+"_trans"
  subprocess.call(['rm',  '-f', outs+"."+filesplits[1], outs+"_O0", outs+"_O3"])

  ## save log file
  cmd = "mv log.txt "+filesplits[0]+"-log.txt"
  subprocess.call(cmd.split(' '))
 
  return None, None, filesplits[0]+"-log.txt"

#def obtain_funcs():
#  #global fglobal.codefile, fglobal.compileops, fglobal.verbose
#
#  status, out, err ="null", "null", "null"
#  cmd = "pLiner "+fglobal.codefile+" -po "+fglobal.compileops
#  FNULL = open(os.devnull, 'w')
#  if fglobal.verbose==1:
#    subprocess.call(cmd.split(' '))
#  else:
#    subprocess.call(cmd.split(' '), stdout=FNULL, stderr=subprocess.STDOUT)
#
#  ans=[]
#  with open('func-list.json') as f:
#    data = json.load(f)
#    funcs = data['pLiner-funcs']
#    for func in funcs:
#      #if func=="initPointer" or func=="main" or func=="rUpdateQuadratureData" or func=="rUpdateQuadratureData3D": ## for Laghos and Varity tests
#      #  continue
#      ans.append(func)	
#
#  return ans  

def search():
  ## obtain functions  
  fglobal.obtain_funcs()

  #global fglobal.logfile
  fglobal.logfile = open("log.txt", "w")
  ## search over the functions
  fsuc, flist=searchfuncs(fglobal.funclist)
  if fsuc:
    fglobal.funclist=flist
  #else:
    #clean_and_exit()   

  ## generate analysis file
  fout = open("pLiner-input.json", "w")
  json.dump({"pLiner-funcs": fglobal.funclist}, fout, sort_keys=True, indent=2, separators=(',', ': '))
  fout.close() 
  cmd = "pLiner "+fglobal.codefile+" -r pLiner-input.json -ao "+fglobal.compileops
  FNULL = open(os.devnull, 'w')
  if fglobal.verbose==1:  
    subprocess.call(cmd.split(' '))
  else:
    subprocess.call(cmd.split(' '), stdout=FNULL, stderr=subprocess.STDOUT)

  forloops, bbs = {}, {}
  for funcname in fglobal.funclist:
    datafile ="pLiner-"+funcname 
    _forloops, _bbs = [], []
    with open(datafile) as json_file:
      data = json.load(json_file)
      _forloops = data['forLoops']
      _bbs = sorted(data['bbList'].values())
      _fbbs = []
      for i in range(len(_bbs)):
        if i==0 or _bbs[i][0]!=_bbs[i-1][0] or _bbs[i][1]!=_bbs[i-1][0]:
          _fbbs.append(_bbs[i])
      
    forloops[funcname]=_forloops
    bbs[funcname]=_fbbs

  ## search loops
  lsuc, llist = searchloops(forloops)
  #print "\n", lsuc, llist


  ## filter bbs and search
  flt_bbs = {}
  for funcname in fglobal.funclist:
    flt_bbs[funcname]=[] 
    _bbs=bbs[funcname]
    _llist=llist[funcname]
    for i in xrange(len(_bbs)):
      bstart, bend = _bbs[i][0], _bbs[i][1]
      if bend<bstart:
        continue
      add=False
      if lsuc:
        for lstart, lend in _llist:
          if bstart >= lstart and bstart <= lend:
            add=True
            break
      if not lsuc or add:
        if len(flt_bbs[funcname])==0: 
          flt_bbs[funcname].append([bstart, bend])
          continue
        if flt_bbs[funcname][-1][1]>=bstart:
          prestart, preend = flt_bbs[funcname][-1][0], flt_bbs[funcname][-1][1]
          flt_bbs[funcname].pop()
          flt_bbs[funcname].append([prestart, max(min(preend, bstart-1), prestart)])
          bstart = max(bstart, preend)
          if bend>=bstart:
            flt_bbs[funcname].append([bstart, bend])
          continue         
        flt_bbs[funcname].append([bstart, bend])
    
  bsuc, bblist = searchbbs(flt_bbs)
  #print "\n", bsuc, bblist

  if not bsuc:
    if lsuc:
      return True, print_and_exit(llist)
    elif fsuc:
      return True, print_and_exit_whole(flist)
    else:
      return False, clean_and_exit()

  ## search lines
  lines = {}
  for funcname in bblist.keys():
    _bblist = bblist[funcname]
    lines[funcname]=[]
    for i in xrange(len(_bblist)):
      bstart, bend = _bblist[i][0], _bblist[i][1]
      for j in xrange(bstart, bend+1):
        lines[funcname].append([j, j])

  nsuc, nlist = searchlines(lines)
  #print "\n", nsuc, nlist

  if not nsuc:
    if bsuc:
      return True, print_and_exit(bblist)
    elif lsuc:
      return True, print_and_exit(llist)
    elif fsuc:
      return True, print_and_exit_whole(flist)
    else:
      return False, clean_and_exit()

  return True, print_and_exit(nlist)

if __name__=="__main__":
  parser=argparse.ArgumentParser(description=
  """pLiner -- search for the origin of compiler-induced inconsistency\r\n
     arg1 : code file that may contain the origin of compiler-induced inconsistency 
     arg2 : the compilation command followed by -- 
   Optional argument list
     arg3 : 0/1 to disable/enable verbose printing, 0 in default 
  e.g., python search.py test.c "--" """, 
  formatter_class=argparse.RawTextHelpFormatter)
  if len(sys.argv)<3:
    parser.print_help(sys.stderr)
    sys.exit(1)
  #args=parser.parse_args()

  #global fglobal.verbose
  #global fglobal.codefile, fglobal.funclist, fglobal.compileops
  fglobal.codefile = sys.argv[1]
  #fglobal.funclist = sys.argv[2].replace('[', ' ').replace(']', ' ').replace(',', ' ').split()
  fglobal.compileops = sys.argv[2]
  fglobal.verbose=0
  if len(sys.argv)==4:
    fglobal.verbose=int(sys.argv[3])

  suc, results = search()
  transfile, regionfile, logfile = results
  if suc:
    print "\n\npLiner succeeded."
    print "Check out ", regionfile, "for the code regions in the original code that cause the inconsistency issue."
    print "Check out ", transfile, " for the transformed code file."
    print "Check out ", logfile, " for the search log"
  else:
    print "\n\npLiner failed to isolate the inconsisency."
    print "Check out ", logfile, " for the search log"
