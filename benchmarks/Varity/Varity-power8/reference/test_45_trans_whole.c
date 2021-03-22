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
 long double comp_H = comp;
 long double var_2_H = var_2;
 long double var_3_H = var_3;
 long double var_4_H = var_4;
 long double var_5_H = var_5;
 long double var_6_H = var_6;
 long double var_7_H = var_7;
 long double var_8_H = var_8;
 long double var_9_H = var_9;
 long double var_10_H = var_10;
 long double var_11_H = var_11;
 long double var_12_H = var_12;
 long double var_13_H = var_13;
 long double var_14_H = var_14;
 long double var_15_H = var_15;
 long double var_16_H = var_16;
 long double var_17_H = var_17;
 long double var_18_H = var_18;
 long double var_19_H = var_19;
 long double var_20_H = var_20;
if (comp_H <= +1.6266E-316 * var_2_H - var_3_H - var_4_H) {
  for (int i=0; i < var_1; ++i) {
    comp_H += (var_5_H / +1.9927E-322 + (-1.4043E306 - var_6_H));
comp_H += var_7_H + (var_8_H * var_9_H - var_10_H);
if (comp_H == -1.0052E305 / var_11_H / expl((-1.1542E305 / var_12_H))) {
  comp_H = var_13_H + acosl((var_14_H + acosl((var_15_H / +1.4681E305 + var_16_H))));
long double tmp_1 = +1.5894E-307;
comp_H += tmp_1 + (var_17_H * var_18_H / (-1.3407E-310 + var_19_H));
}
if (comp_H == cosl(-1.3511E-320 * cosl(-1.1104E306 / -1.0653E171))) {
  comp_H += +1.3631E306 + (var_20_H - +1.7779E305 + +1.2478E-323);
}
}
}
   printf("%.17Lg\n", comp_H);

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
