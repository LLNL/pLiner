import os
from subprocess import PIPE, run

def run_command(command):
    result = run(command, stdout=PIPE, stderr=PIPE, universal_newlines=True, shell=True)
    return result.stdout

def run_cg_b():

    os.system("rm -r CG && cp -r CG.B CG && make cg CLASS=B")
    current_path = run_command("pwd").strip()
    os.chdir(current_path+"/CG")
    os.system('python ../../../../scripts/search.py cg.c "-- -c -I../common -g -Wall -O3 -mcmodel=medium -ffast-math"')
    os.chdir(current_path)

def run_sp_b():
    os.system("rm -r SP && cp -r SP.B SP && make SP  CLASS=B")
    current_path = run_command("pwd").strip()
    os.chdir(current_path+"/SP")
    os.system('python ../../../../scripts/search-mul.py mine.csv "-- -c -I../common -g -Wall -O3 -mcmodel=medium -ffast-math"')
    os.chdir(current_path)
    

def run_sp_a():
    os.system("rm -r SP && cp -r SP.A SP && make SP  CLASS=A")
    current_path = run_command("pwd").strip()
    os.chdir(current_path+"/SP")
    os.system('python ../../../../scripts/search-mul.py mine.csv "-- -c -I../common -g -Wall -O3 -mcmodel=medium -ffast-math"')
    os.chdir(current_path)


run_cg_b()
run_sp_b()
os.system("cp -r SP SP_B_FINAL")
run_sp_a()

