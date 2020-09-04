/* command----------------------------------------------------------------lassen191_36621_tests_group_1_test_7.c
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O0 -O0 test.c -lm
$ ./test_O0 -1.4311E305 5 +1.5661E-319 +1.8570E-53 +1.3889E-319 +1.7226E-317 +0.0 +0.0 -1.6267E-321 -1.3016E305 +1.0714E305 +0.0 +1.5113E43 +0.0 -1.6438E-313 -1.6723E-314 -0.0 +1.6989E306 +1.6382E-307 +1.2312E-311 +1.7256E-306
-7.7003100000000022e+306
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O3 -O3 test.c -lm
$ ./test_O3 -1.4311E305 5 +1.5661E-319 +1.8570E-53 +1.3889E-319 +1.7226E-317 +0.0 +0.0 -1.6267E-321 -1.3016E305 +1.0714E305 +0.0 +1.5113E43 +0.0 -1.6438E-313 -1.6723E-314 -0.0 +1.6989E306 +1.6382E-307 +1.2312E-311 +1.7256E-306
inf
--------------------------------------------------------------------------*/

/* This is a automatically generated test. Do not modify */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void compute(double comp, int var_1,double var_2,double var_3,double var_4,double var_5,double var_6,double var_7,double var_8,double var_9,double var_10,double var_11,double var_12,double var_13,double var_14,double var_15,double var_16,double var_17,double var_18,double var_19,double var_20) {
if (comp <= +1.6266E-316 * var_2 - var_3 - var_4) {
  for (int i=0; i < var_1; ++i) {
    comp += (var_5 / +1.9927E-322 + (-1.4043E306 - var_6));
comp += var_7 + (var_8 * var_9 - var_10);
if (comp == -1.0052E305 / var_11 / exp((-1.1542E305 / var_12))) {
  comp = var_13 + acos((var_14 + acos((var_15 / +1.4681E305 + var_16))));
double tmp_1 = +1.5894E-307;
comp += tmp_1 + (var_17 * var_18 / (-1.3407E-310 + var_19));
}
if (comp == cos(-1.3511E-320 * cos(-1.1104E306 / -1.0653E171))) {
  comp += +1.3631E306 + (var_20 - +1.7779E305 + +1.2478E-323);
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
  double tmp_16 = atof(argv[16]);
  double tmp_17 = atof(argv[17]);
  double tmp_18 = atof(argv[18]);
  double tmp_19 = atof(argv[19]);
  double tmp_20 = atof(argv[20]);
  double tmp_21 = atof(argv[21]);

  compute(tmp_1,tmp_2,tmp_3,tmp_4,tmp_5,tmp_6,tmp_7,tmp_8,tmp_9,tmp_10,tmp_11,tmp_12,tmp_13,tmp_14,tmp_15,tmp_16,tmp_17,tmp_18,tmp_19,tmp_20,tmp_21);

  return 0;
}
