This folder includes two set of Varity programs:
  (1) Varity-power8 : 50 varity programs that have inconsistency problems when compiling the program with "xlc -O3" comparing to "xlc -O0" on power8 platform
  (2) Varity-intel  : 50 varity programs that have inconsistency problems when compiling the program with "gcc -O3 -ffast-math" comparing to "gcc -O0" on intel x86 platform

To observe the inconsistencies, go to the corresponding subfolder and run, 
  (1) make
  (2) ./cmp.sh test_XX
