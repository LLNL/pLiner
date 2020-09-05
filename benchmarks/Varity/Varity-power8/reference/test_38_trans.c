/* command----------------------------------------------------------------lassen442_6864_tests_group_7_test_10.c
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O0 -O0 test.c -lm
$ ./test_O0 -1.6532E196 5 -1.5824E305 +0.0 -1.6748E269 +1.0513E-307 +1.5953E-306 +1.0673E-306 -1.5292E305 -1.2835E83 -0.0 +1.1113E306 -1.4449E-310 +1.8344E-319 -1.7884E-306
-1.444e+305
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O3 -O3 test.c -lm
$ ./test_O3 -1.6532E196 5 -1.5824E305 +0.0 -1.6748E269 +1.0513E-307 +1.5953E-306 +1.0673E-306 -1.5292E305 -1.2835E83 -0.0 +1.1113E306 -1.4449E-310 +1.8344E-319 -1.7884E-306
-1.6532e+196
--------------------------------------------------------------------------*/

/* This is a automatically generated test. Do not modify */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void compute(double comp, int var_1,double var_2,double var_3,double var_4,double var_5,double var_6,double var_7,double var_8,double var_9,double var_10,double var_11,double var_12,double var_13,double var_14) {
if (comp < (var_2 / -1.3223E291 / (+0.0 * var_3))) {
  long double comp_18_29_H = comp;
  for (int i=0; i < var_1; ++i) {
    comp_18_29_H = ((long double)var_4 * (-1.9589E-322 * (+1.6242E-306 - (+1.1704E306 - (long double)var_5))));
comp_18_29_H = log10l(((long double)var_6 / (long double)var_7));
if (comp_18_29_H >= fabsl(-1.3430E-307)) {
  long double tmp_1_18_29_H = -1.8244E-307;
comp_18_29_H = tmp_1_18_29_H * (long double)var_8 * +1.3042E224 + (-1.9130E-322 * (long double)var_9 - +1.4440E305);
comp_18_29_H += (long double)var_10 * (long double)var_11;
}
if (comp_18_29_H == sinl((-0.0 * (long double)var_12))) {
  comp_18_29_H = ((long double)var_13 / ((long double)var_14 - -1.4423E-158));comp = comp_18_29_H;
  
}
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

  compute(tmp_1,tmp_2,tmp_3,tmp_4,tmp_5,tmp_6,tmp_7,tmp_8,tmp_9,tmp_10,tmp_11,tmp_12,tmp_13,tmp_14,tmp_15);

  return 0;
}
