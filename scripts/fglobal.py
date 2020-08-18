import subprocess, os
import json

def fglobal_init():
  global verbose, logfile
  global codefile, funclist, compileops


def obtain_funcs():
  global codefile, compileops, funclist, verbose

  status, out, err ="null", "null", "null"
  cmd = "pLiner "+codefile+" -po "+compileops
  FNULL = open(os.devnull, 'w')
  if verbose==1:
    subprocess.call(cmd.split(' '))
  else:
    subprocess.call(cmd.split(' '), stdout=FNULL, stderr=subprocess.STDOUT)

  allfuncs=[]
  with open('func-list.json') as f:
    data = json.load(f)
    funcs = data['pLiner-funcs']
    allfuncs = funcs[::]
   
  exclude=[]
  if os.path.isfile('./exclude.json'):
    with open('exclude.json') as f:
      data = json.load(f)
      if codefile in data:
        funcs = data[codefile]
        exclude = funcs[::]
  
  func2explore=[item for item in allfuncs if item not in exclude]
  funclist = func2explore[::]

  return func2explore 
