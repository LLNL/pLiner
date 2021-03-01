## README for Varity-Intel folder
This folder includes two set of Varity programs:
  (1) Varity-power8 : 50 varity programs that have inconsistency problems when compiling the program with "xlc -O3" comparing to "xlc -O0" on power8 platform
  (2) Varity-intel  : 50 varity programs that have inconsistency problems when compiling the program with "gcc -O3 -ffast-math" comparing to "gcc -O0" on intel x86 platform

To observe the inconsistencies, go to the corresponding subfolder and run, 
  (1) make
  (2) ./cmp.sh test_XX
  
### Steps to run Varity-Intel program.
1.Run the docker container
  ```
  docker run -it <tag-name> /bin/bash
  ```
2.Switch to dev branch
  ```
  git checkout dev
  ```
3.Navigate to the folder containing Varity-Intel programs and make a copy.
  ```
  cd pLiner/benchmarks/Varity
  cp -r Varity-intel Varity-intel-copy
  ```
4.Switch back to master branch and run pLiner on Varity prgrams.
  ```
  git checkout master
  cd Varity-intel-copy
  python ../../../scripts/search.py test_1.c "--"
  ```
  #### Note:
  The Varity-intel-copy folder contains reference results for the Varity-intel programs.
  
  