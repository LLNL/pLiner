import json
import sys
import subprocess
import os
import argparse

class loopStruct:
  def __init__(self, start, end):
    self.start, self.end = start, end
    self.innerloops = []
  def isInnerLoop(self, start, end):
    return start>self.start and end<self.end
  def addInnerLoop(self, start, end):
    self.innerloops.append([start, end])
  def getLoop(self):
    return self.start, self.end
  def getInnerLoops(self):
    return self.innerloops

class loopList:
  def __init__(self, _forloops):
    self.loops = []
    for start, end in _forloops:
      added = False
      for l in self.loops:
        if l.isInnerLoop(start, end):
	  l.addInnerLoop(start, end)
          added = True
      if not added:
        loop = loopStruct(start, end)
        self.loops.append(loop)

  def getLoopList(self):
    return self.loops 


def splitloops(_forloops):
  _forloops.sort(key=lambda s:s[0])
  looplist = loopList(_forloops)
  return looplist.getLoopList()

def trans_and_run(fregion):
  global codefile, funclist, compileops, msgout
  filesplits = codefile.split(".")
  outfile=filesplits[0]+"_trans."+filesplits[1]
  subprocess.call(['rm',  '-f', outfile])

  status, out, err ="null", "null", "null"
  cmd = "pLiner "+codefile+" -r="+fregion+" -o="+outfile+" "+compileops 
  #print cmd
  FNULL = open(os.devnull, 'w')
  if msgout==1:  
    subprocess.call(cmd.split(' '))
  else:
    subprocess.call(cmd.split(' '), stdout=FNULL, stderr=subprocess.STDOUT)
  
  if not os.path.exists(outfile):
    status="trans error"
    print "transformation failed."
    return False

  #print "./run.sh ", outfile
  ret = subprocess.call("./run.sh "+outfile, shell=True, stdout=None, stderr=None)
  if ret:
    status="success"
    print "success"
    flog = open("runlog.txt", "r")
    logs = flog.readlines()
    out, err = logs[0].rstrip('\n'), logs[1].rstrip('\n')   

  else:
    status="failed"
    print "failed"
  
  return ret, status, out, err

def funcrun(flist):
  global codefile, compileops, msgout
  filesplits = codefile.split(".")
  outfile=filesplits[0]+"_trans."+filesplits[1]
  subprocess.call(['rm',  '-f', outfile])

  status, out, err ="null", "null", "null"
  fout = open(filesplits[0]+"-regions.json", "w")
  json.dump({"pLiner-funcs": flist}, fout, sort_keys=True, indent=2, separators=(',', ': '))
  fout.close()
  cmd = "pLiner "+codefile+" --whole -r="+filesplits[0]+"-regions.json"+" -o="+outfile+" "+compileops 
  #print cmd
  FNULL = open(os.devnull, 'w')
  if msgout==1:  
    subprocess.call(cmd.split(' '))
  else:
    subprocess.call(cmd.split(' '), stdout=FNULL, stderr=subprocess.STDOUT)

  if not os.path.exists(outfile):
    status="trans error"
    print "transformation failed."
    return False

  #print "./run.sh ", outfile
  ret = subprocess.call("./run.sh "+outfile, shell=True, stdout=None, stderr=None)
  if ret:
    status="success"
    print "success"
    flog = open("runlog.txt", "r")
    logs = flog.readlines()
    out, err = logs[0].rstrip('\n'), logs[1].rstrip('\n')   

  else:
    status="failed"
    print "failed"
  
  logstr = "FUNCTIONs: " + str(flist) + ", " + status +", " + out +", " + err + "\n"
  logfile.write(logstr)
  return ret

def looprun(llist, typestr="LOOP"):
  global codefile, funclist, compileops, logfile
  print "The following areas are transformed to high precision:"

  regions = {}
  for f in llist.keys():
    regions[f]=[]
    print f, ":"
    for l in llist[f]:
      lstart, lend = l.getLoop()
      regions[f].append([lstart, lend])
      print "  ", lstart, "->", lend 

  filesplits = codefile.split(".")
  fout = open(filesplits[0]+"-regions.json", "w")
  json.dump({"pLiner-funcs": funclist, "pLiner-fregions": regions}, fout, sort_keys=True, indent=2, separators=(',', ': '))
  fout.close()
  ret, status, out, err = trans_and_run(filesplits[0]+"-regions.json")
  logstr = typestr+"s: " + str(regions) + ", " + status +", " + out +", " + err + "\n"
  logfile.write(logstr)
  return ret

def bbrun(bblist, typestr="BB"):
  global codefile, funclist, compileops, logfile
  print "The following areas are transformed to high precision:"

  regions = {}
  for f in bblist.keys():
    regions[f]=[]
    print f, ":"
    for bstart, bend in bblist[f]:
      regions[f].append([bstart, bend])
      print "  ", bstart, "->", bend 

  filesplits = codefile.split(".")
  fout = open(filesplits[0]+"-regions.json", "w")
  json.dump({"pLiner-funcs": funclist, "pLiner-fregions": regions}, fout, sort_keys=True, indent=2, separators=(',', ': '))
  fout.close()
  ret, status, out, err = trans_and_run(filesplits[0]+"-regions.json")
  logstr = typestr+"s: " + str(regions) + ", " + status +", " + out +", " + err + "\n"
  logfile.write(logstr)
  return ret
 
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
  print "Search for functions:"

  # step 1: translate all funcs   
  if not funcrun(flist):
    print "transforming all buggy functions does not fix the bug"
    return False, flist

  # step 2: perform bisection search over the funcs
  _flist = flist[::]
  size=len(_flist)
  while size>1:
    half = size/2
    left, right = _flist[:half], _flist[half:]
    if funcrun(left):
      _flist, size = left, len(left)
      continue
    if funcrun(right):
      _flist, size = right, len(right)
      continue
    break

  return True, _flist

def searchloops(rawloops):
  #return True, [[92, 190]]

  print "Search for loops:"

  # step 1: translate the outermost loops   
  tranloops={}
  for func in rawloops.keys():
    _loops = rawloops[func]
    _toploops = splitloops(_loops)
    tranloops[func] = _toploops

  ret = {}
  if not looprun(tranloops):
    print "transforming for loops does not fix the bug"
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
  print "Search for bbs:"
  # step 1: translate all bbs   
  if not bbrun(bbs):
    print "transforming all buggy bbs does not fix the bug"
    return False, bbs

  # step 2: perform bisection search over the bbs of each function
  for f in bbs.keys():
    _bbs = bisection(bbs, f, "BB")
    bbs[f]=_bbs

  return True, bbs

def searchlines(lines):
  print "Search for lines:"
  # step 1: translate all lines   
  if not bbrun(lines, "LINE"):
    print "transforming all buggy lines does not fix the bug"
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

  global codefile, funclist, compileops, logfile, msgout
  filesplits = codefile.split(".")

  ## generate final region log file
  fout = open(filesplits[0]+"-regions.json", "w")
  json.dump({"pLiner-funcs": funclist, "pLiner-fregions": nlist}, fout, sort_keys=True, indent=2, separators=(',', ': '))
  fout.close()
  logfile.close()

  ## generate final transformated program
  outfile=filesplits[0]+"_trans."+filesplits[1]
  subprocess.call(['rm',  '-f', outfile])

  status, out, err ="null", "null", "null"
  cmd = "pLiner "+codefile+" -r="+filesplits[0]+"-regions.json -o="+outfile+" "+compileops 
  FNULL = open(os.devnull, 'w')
  if msgout==1:  
    subprocess.call(cmd.split(' '))
  else:
    subprocess.call(cmd.split(' '), stdout=FNULL, stderr=subprocess.STDOUT)

  ## save log file
  cmd = "mv log.txt "+filesplits[0]+"-log.txt"
  subprocess.call(cmd.split(' '))
  
  exit(0)

def clean_and_exit():
  global codefile
  ## remove TEST_trans.c
  filesplits = codefile.split(".")
  outs=filesplits[0]+"_trans"
  subprocess.call(['rm',  '-f', outs+"."+filesplits[1], outs+"_O0", outs+"_O3"])

  ## save log file
  cmd = "mv log.txt "+filesplits[0]+"-log.txt"
  subprocess.call(cmd.split(' '))
 
  exit(-1)

def obtain_funcs():
  global codefile, compileops, msgout

  status, out, err ="null", "null", "null"
  cmd = "pLiner "+codefile+" -po "+compileops
  FNULL = open(os.devnull, 'w')
  if msgout==1:
    subprocess.call(cmd.split(' '))
  else:
    subprocess.call(cmd.split(' '), stdout=FNULL, stderr=subprocess.STDOUT)

  ans=[]
  with open('func-list.json') as f:
    data = json.load(f)
    funcs = data['pLiner-funcs']
    for func in funcs:
      if func=="initPointer" or func=="main" or func=="rUpdateQuadratureData" or func=="rUpdateQuadratureData3D": ## for Laghos and Varity tests
        continue
      ans.append(func)	

  return ans  


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

  global msgout
  global codefile, funclist, compileops
  codefile = sys.argv[1]
  #funclist = sys.argv[2].replace('[', ' ').replace(']', ' ').replace(',', ' ').split()
  compileops = sys.argv[2]
  msgout=0
  if len(sys.argv)==4:
    msgout=int(sys.argv[3])
  
  funclist = obtain_funcs()

  global logfile
  logfile = open("log.txt", "w")
  ## search over the functions
  fsuc, flist=searchfuncs(funclist)
  if fsuc:
    funclist=flist
  #else:
    #clean_and_exit()   

  ## generate analysis file
  fout = open("pLiner-input.json", "w")
  json.dump({"pLiner-funcs": funclist}, fout, sort_keys=True, indent=2, separators=(',', ': '))
  fout.close() 
  cmd = "pLiner "+codefile+" -r pLiner-input.json -ao "+compileops
  FNULL = open(os.devnull, 'w')
  if msgout==1:  
    subprocess.call(cmd.split(' '))
  else:
    subprocess.call(cmd.split(' '), stdout=FNULL, stderr=subprocess.STDOUT)



  forloops, bbs = {}, {}
  for funcname in funclist:
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
  for funcname in funclist:
    flt_bbs[funcname]=[] 
    _bbs=bbs[funcname]
    _llist=llist[funcname]
    for i in xrange(len(_bbs)):
      bstart, bend = _bbs[i][0], _bbs[i][1]
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
      print_and_exit(llist)
    else:
      clean_and_exit()

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
      print_and_exit(bblist)
    elif lsuc:
      print_and_exit(llist)
    else:
      clean_and_exit()

  print_and_exit(nlist)


