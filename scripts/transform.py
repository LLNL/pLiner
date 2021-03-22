import json
import sys
import subprocess
import os

from loopst import *
import fglobal


def singlefiletrans():
  filesplits = fglobal.codefile.split(".")
  outfile=filesplits[0]+"_trans."+filesplits[1]
  subprocess.call(['rm',  '-f', outfile])

  fglobal.obtain_funcs()

  print "\n[", fglobal.codefile, "]The following functions are transformed to high precision:"
  print fglobal.funclist

  status, out, err ="null", "null", "null"
  fout = open(filesplits[0]+"-regions.json", "w")
  json.dump({"pLiner-funcs": fglobal.funclist}, fout, sort_keys=True, indent=2, separators=(',', ': '))
  fout.close()
  cmd = "pLiner "+fglobal.codefile+" --whole -r="+filesplits[0]+"-regions.json"+" -o="+outfile+" "+fglobal.compileops
  #print cmd
  FNULL = open(os.devnull, 'w')
  if fglobal.verbose==1:
    subprocess.call(cmd.split(' '))
  else:
    subprocess.call(cmd.split(' '), stdout=FNULL, stderr=subprocess.STDOUT)

  trans = False
  if os.path.exists(outfile):
    trans = True

  return trans, outfile

def filerun(filedict, logfile):
  files=filedict.values()
  farg=" ".join(files)

  print "\nThe following files are transformed to high precision:"
  print filedict.keys()

  comp, exect, const = False, False, False
  status, out, err = "null", "null", "null"
  ret = subprocess.call("./run.sh "+farg, shell=True, stdout=None, stderr=None)
  if ret==0:
    status="success"
    print "success"
    flog = open("runlog.txt", "r")
    logs = flog.readlines()
    out, err = logs[0].rstrip('\n'), logs[1].rstrip('\n')
    comp, exect, const = True, True, True
  elif ret==1:
    status="compilation error"
    print "compilation failed"
  elif ret==2:
    status="execution error"
    comp = True
    print "execution failed"
  elif ret==3:
    status="inconsistent results"
    comp, exect = True, True
    print "consistency check failed"

  logstr = "FILEs: " + str(filedict.keys()) + ", " + status +", " + out +", " + err + "\n"
  logfile.write(logstr)
  return comp, exect, const

def funcrun(flist):
  #global fglobal.codefile, fglobal.compileops, fglobal.verbose
  filesplits = fglobal.codefile.split(".")
  outfile=filesplits[0]+"_trans."+filesplits[1]
  subprocess.call(['rm',  '-f', outfile])

  print "\nThe following functions are transformed to high precision:"
  print flist

  status, out, err ="null", "null", "null"
  fout = open(filesplits[0]+"-regions.json", "w")
  json.dump({"pLiner-funcs": flist}, fout, sort_keys=True, indent=2, separators=(',', ': '))
  fout.close()
  cmd = "pLiner "+fglobal.codefile+" --whole -r="+filesplits[0]+"-regions.json"+" -o="+outfile+" "+fglobal.compileops
  #print cmd
  FNULL = open(os.devnull, 'w')
  if fglobal.verbose==1:
    subprocess.call(cmd.split(' '))
  else:
    subprocess.call(cmd.split(' '), stdout=FNULL, stderr=subprocess.STDOUT)

  trans, comp, exect, const = False, False, False, False
  if not os.path.exists(outfile):
    status="transformation error"
    print "transformation failed"
    logstr = "FUNCTIONs: " + str(flist) + ", " + status +", " + out +", " + err + "\n"
    fglobal.logfile.write(logstr) 
    return trans, comp, exect, const

  #print "./run.sh ", outfile
  trans = True
  ret = subprocess.call("./run.sh "+outfile, shell=True, stdout=None, stderr=None)
  if ret==0:
    status="success"
    print "success"
    flog = open("runlog.txt", "r")
    logs = flog.readlines()
    out, err = logs[0].rstrip('\n'), logs[1].rstrip('\n')
    comp, exect, const = True, True, True
  elif ret==1:
    status="compilation error"
    print "compilation failed"
  elif ret==2:
    status="execution error"
    comp = True
    print "execution failed"
  elif ret==3:
    status="inconsistent results"
    comp, exect = True, True
    print "consistency check failed"

  logstr = "FUNCTIONs: " + str(flist) + ", " + status +", " + out +", " + err + "\n"
  fglobal.logfile.write(logstr)
  return trans, comp, exect, const

def trans_and_run(fregion):
  #global fglobal.codefile, fglobal.funclist, fglobal.compileops, fglobal.verbose
  filesplits = fglobal.codefile.split(".")
  outfile=filesplits[0]+"_trans."+filesplits[1]
  subprocess.call(['rm',  '-f', outfile])

  status, out, err ="null", "null", "null"
  cmd = "pLiner "+fglobal.codefile+" -r="+fregion+" -o="+outfile+" "+fglobal.compileops 
  #print cmd
  FNULL = open(os.devnull, 'w')
  if fglobal.verbose==1:  
    subprocess.call(cmd.split(' '))
  else:
    subprocess.call(cmd.split(' '), stdout=FNULL, stderr=subprocess.STDOUT)
  
  trans, comp, exect, const = False, False, False, False
  if not os.path.exists(outfile):
    status="transformation error"
    print "transformation failed."
    return trans, comp, exect, const, status, out, err

  #print "./run.sh ", outfile
  trans=True
  ret = subprocess.call("./run.sh "+outfile, shell=True, stdout=None, stderr=None)
  if ret==0:
    status="success"
    print "success"
    flog = open("runlog.txt", "r")
    logs = flog.readlines()
    out, err = logs[0].rstrip('\n'), logs[1].rstrip('\n')
    comp, exect, const = True, True, True   
  elif ret==1:
    status="compilation error"
    print "compilation failed"
  elif ret==2:
    status="execution error"
    print "execution failed"
    comp = True
  elif ret==3:
    status="inconsistent results"
    print "consistency check failed"
    comp, exect = True, True

  return trans, comp, exect, const, status, out, err


def looprun(llist, typestr="LOOP"):
  #global fglobal.codefile, fglobal.funclist, fglobal.compileops, fglobal.logfile
  print "\nThe following areas are transformed to high precision:"

  regions = {}
  for f in llist.keys():
    regions[f]=[]
    print f, ":"
    for l in llist[f]:
      lstart, lend = l.getLoop()
      regions[f].append([lstart, lend])
      print "  ", lstart, "->", lend

  filesplits = fglobal.codefile.split(".")
  fout = open(filesplits[0]+"-regions.json", "w")
  json.dump({"pLiner-funcs": fglobal.funclist, "pLiner-fregions": regions}, fout, sort_keys=True, indent=2, separators=(',', ': '))
  fout.close()
  trans, comp, exect, const, status, out, err = trans_and_run(filesplits[0]+"-regions.json")
  logstr = typestr+"s: " + str(regions) + ", " + status +", " + out +", " + err + "\n"
  fglobal.logfile.write(logstr)
  return const

def bbrun(bblist, typestr="BB"):
  #global fglobal.codefile, fglobal.funclist, fglobal.compileops, fglobal.logfile
  print "\nThe following areas are transformed to high precision:"

  regions = {}
  for f in bblist.keys():
    regions[f]=[]
    print f, ":"
    for bstart, bend in bblist[f]:
      regions[f].append([bstart, bend])
      print "  ", bstart, "->", bend

  filesplits = fglobal.codefile.split(".")
  fout = open(filesplits[0]+"-regions.json", "w")
  json.dump({"pLiner-funcs": fglobal.funclist, "pLiner-fregions": regions}, fout, sort_keys=True, indent=2, separators=(',', ': '))
  fout.close()
  trans, comp, exect, const, status, out, err = trans_and_run(filesplits[0]+"-regions.json")
  logstr = typestr+"s: " + str(regions) + ", " + status +", " + out +", " + err + "\n"
  fglobal.logfile.write(logstr)
  return const
