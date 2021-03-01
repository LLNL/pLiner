/* command----------------------------------------------------------------lassen439_81565_tests_group_3_test_5.c
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O0 -O0 test.c -lm
$ ./test_O0 +0.0 5 -1.0184E-311 +1.7067E277 -1.6847E-306 +1.8873E-321 -1.7196E132 -1.9874E-320 +1.0539E-307 -1.2192E-306 +0.0 +1.0069E305 -1.3774E-306 -1.2990E-317 +0.0 +1.6335E-307 -1.6584E-162
nan
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O3 -O3 test.c -lm
$ ./test_O3 +0.0 5 -1.0184E-311 +1.7067E277 -1.6847E-306 +1.8873E-321 -1.7196E132 -1.9874E-320 +1.0539E-307 -1.2192E-306 +0.0 +1.0069E305 -1.3774E-306 -1.2990E-317 +0.0 +1.6335E-307 -1.6584E-162
1.3407639380493153
--------------------------------------------------------------------------*/


/* This is a automatically generated test. Do not modify */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void compute(double comp, int var_1,double var_2,double var_3,double var_4,double var_5,double var_6,double var_7,double var_8,double var_9,double var_10,double var_11,double var_12,double var_13,double var_14,double var_15,double var_16) {
for (int i=0; i < var_1; ++i) {
  comp += (var_2 / +1.6922E305 - (var_3 - var_4));
comp += cos(-1.4280E-322 + acos(var_5 + -1.3779E211 + -1.4439E-179));
comp += +0.0 + (var_6 - var_7);
if (comp <= var_8 + (var_9 - var_10)) {
  comp = -1.2323E-159 + +1.1231E117 * var_11;
comp = var_12 / fmod(-1.7222E223 - (var_13 - -1.0890E-307), +1.3373E-306);
comp += (var_14 + sinh(var_15 + -0.0 * var_16));
}
}
   printf("%.17g\n", comp);

}

double* initPointer(double v) {
  double *ret = (double*) malloc(sizeof(double)*10);
  for(int i=0; i < 10; ++i)
    ret[i] = v;
  return ret;
}

int main(int argc, char** argv) {
/* Program variables */

  double tmp_1 = atof(argv[1]);
  int tmp_2 = atoi(argv[2]);
  double tmp_3 = atof(argv[3]);
  double tmp_4 = atof(argv[4]);
  double tmp_5 = atof(argv[5]);
  double tmp_6 = atof(argv[6]);
  double tmp_7 = atof(argv[7]);
  double tmp_8 = atof(argv[8]);
  double tmp_9 = atof(argv[9]);
  double tmp_10 = atof(argv[10]);
  double tmp_11 = atof(argv[11]);
  double tmp_12 = atof(argv[12]);
  double tmp_13 = atof(argv[13]);
  double tmp_14 = atof(argv[14]);
  double tmp_15 = atof(argv[15]);
  double tmp_16 = atof(argv[16]);
  double tmp_17 = atof(argv[17]);

  compute(tmp_1,tmp_2,tmp_3,tmp_4,tmp_5,tmp_6,tmp_7,tmp_8,tmp_9,tmp_10,tmp_11,tmp_12,tmp_13,tmp_14,tmp_15,tmp_16,tmp_17);

  return 0;
}
