import json, csv
import sys
import subprocess
import os
import argparse

import fglobal
from transform import *
import search

def prRed(skk): print("\033[91m {}\033[00m" .format(skk)) 
def prGreen(skk): print("\033[92m {}\033[00m" .format(skk)) 
def prYellow(skk): print("\033[93m {}\033[00m" .format(skk)) 
def prLightPurple(skk): print("\033[94m {}\033[00m" .format(skk)) 
def prPurple(skk): print("\033[95m {}\033[00m" .format(skk)) 
def prCyan(skk): print("\033[96m {}\033[00m" .format(skk)) 
def prLightGray(skk): print("\033[97m {}\033[00m" .format(skk)) 
def prBlack(skk): print("\033[98m {}\033[00m" .format(skk)) 


def clean_and_exit():
  ## remove TEST_trans.c
  #filesplits = fglobal.codefile.split(".")
  #subprocess.call(['rm',  '-f', "*_trans."+filesplits[1], "*_trans_O0", "*_trans_O3"])
 
  print "\n\npLiner failed to isolate the inconsistency."
  print "Check out the logs: plog.txt"
  exit(-1)


def searchfiles():
  prPurple("\n\nSearch for files:")

  global pfiles, pcompileops, pverbose, pfile_trans, plogfile

  # step 1: translate all files
  for currfile in pfiles:
    fglobal.codefile, fglobal.compileops, fglobal.verbose = currfile, pcompileops, pverbose
    trans, ftrans = singlefiletrans()
    if trans:
      pfile_trans[currfile] = ftrans
   
  comp, exect, const = filerun(pfile_trans, plogfile) 
  if not comp or not exect:
    _filelist = []
    for currfile in pfile_trans.keys():
      _comp, _exect, _const = filerun({currfile: pfile_trans[currfile]}, plogfile)
      if _comp and _exect:
        _filelist.append(currfile)
      else:
        del pfile_trans[currfile]
    perc=len(_filelist)*100.0/len(pfiles)
    print perc, "% (", len(_filelist), " out of ", len(pfiles), " files) can be handled in pLiner.\n"
    pfiles = _filelist[::]
    comp, exect, const = filerun(pfile_trans, plogfile) 

  if not const:
    prRed("transforming all files does not fix the bug")
    return False, pfiles

  # step 2: perform bisection search over the files
  _flist = pfiles[::]
  size=len(_flist)
  while size>1:
    half = size/2
    left, right = _flist[:half], _flist[half:]
    leftdict, rightdict = {}, {}
    for item in left:
      leftdict[item]=pfile_trans[item]
    for item in right:
      rightdict[item]=pfile_trans[item]
    lcomp, lexect, lconst = filerun(leftdict, plogfile) 
    if lconst:
      _flist, size = left, len(left)
      continue
    rcomp, rexect, rconst = filerun(rightdict, plogfile) 
    if rconst:
      _flist, size = right, len(right)
      continue
    break

  return True, _flist

def copy_to_trans(flist):
  global pfile_trans
  for fl in flist:
    cmd = "mv "+fl+" "+pfile_trans[func] 
    subprocess.call(cmd.split(' '), stdout=FNULL, stderr=subprocess.STDOUT)

def copy_to_ori(flist):
  for fl in flist:
    cmd = "mv "+fl+" "+fl+".ori" 
    subprocess.call(cmd.split(' '), stdout=FNULL, stderr=subprocess.STDOUT)
  
if __name__=="__main__":
  parser=argparse.ArgumentParser(description=
  """pLiner -- search for the origin of compiler-induced inconsistency\r\n
     arg1 : csv file that lists the code files to explore 
     arg2 : the compilation command followed by -- 
   Optional argument list
     arg3 : 0/1 to disable/enable verbose printing, 0 in default 
  e.g., python search.py test.c "--" """, 
  formatter_class=argparse.RawTextHelpFormatter)
  if len(sys.argv)<3:
    parser.print_help(sys.stderr)
    sys.exit(1)

  global pfiles, pcompileops, pverbose, pfile_trans, plogfile
  pcsv, pcompileops, pverbose = sys.argv[1], sys.argv[2], 0
  if len(sys.argv)==4:
    pverbose=int(sys.argv[3])

  ## read file list
  pfiles=[]
  with open(pcsv, 'rb') as csvfile:
    spamreader = csv.reader(csvfile, delimiter=' ')
    for row in spamreader:
      pfiles.extend(row)
  pfile_trans={}

  ## bisection search over files
  plogfile = open("plog.txt", "w")
  suc, filelist = searchfiles()

  if not suc:
    plogfile.close()
    clean_and_exit()

  ## search each single file
  fglobal.compileops, fglobal.verbose = pcompileops, pverbose
  for i, fl in enumerate(filelist):
    rest=filelist[:i]+filelist[i+1:]
    copy_to_trans(rest)
    fglobal.codefile = fl
    suc, results = search.search()
    transfile, regionfile, logfile = results
    copy_to_ori(rest)
    with open(logfile) as logfp: 
      loglines = logfp.readlines()
      for line in loglines:
        plogfile.write(fl+" :: "+line)
    if not suc:
      plogfile.close()
      clean_and_exit()
    pfile_trans[fl]=transfile

  plogfile.close()
  print "\n\npLiner succeeded."
  print "Check out plog.txt for the search log"
  print "Check out the isolated regions and transformed files for the following code files:"
  print filelist      
