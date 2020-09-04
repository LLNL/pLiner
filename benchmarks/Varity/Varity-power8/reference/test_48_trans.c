/* command----------------------------------------------------------------lassen233_43893_tests_group_5_test_4.c
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O0 -O0 test.c -lm
$ ./test_O0 -0.0 -1.9042E223 +1.1392E-306 -1.4442E-49 5 +1.5940E262 -1.0685E-306 +1.3131E306 +1.7827E-306 +1.6055E-146 +1.5467E243 +1.1100E305 +0.0 +1.2366E-226 -1.5493E54 +0.0 -1.6556E-320 -1.9029E-307 -1.7353E-306 +1.7788E-242 -0.0 -1.3944E-315 -1.6323E-316 +1.9972E306 +0.0 -1.9804E-307
nan
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O3 -O3 test.c -lm
$ ./test_O3 -0.0 -1.9042E223 +1.1392E-306 -1.4442E-49 5 +1.5940E262 -1.0685E-306 +1.3131E306 +1.7827E-306 +1.6055E-146 +1.5467E243 +1.1100E305 +0.0 +1.2366E-226 -1.5493E54 +0.0 -1.6556E-320 -1.9029E-307 -1.7353E-306 +1.7788E-242 -0.0 -1.3944E-315 -1.6323E-316 +1.9972E306 +0.0 -1.9804E-307
-1.1547178538390379
--------------------------------------------------------------------------*/

/* This is a automatically generated test. Do not modify */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void compute(double comp, double var_1,double var_2,double var_3,int var_4,double var_5,double var_6,double var_7,double var_8,double var_9,double var_10,double var_11,double var_12,double var_13,double var_14,double var_15,double var_16,double var_17,double var_18,double var_19,double var_20,double var_21,double var_22,double var_23,double var_24,double var_25) {
if (comp <= (-0.0 * +0.0 * var_1 - var_2 / -1.1792E-184)) {
  if (comp >= +1.7696E-306 / var_3) {
    comp += (-0.0 / tanh(var_5 - +1.7056E305));
comp += asin((-0.0 / (-1.5586E306 + var_6 + floor(asin(+1.5697E165 / (var_7 + (-0.0 - var_8 + +1.0778E-312)))))));
comp = (var_9 * var_10 + floor(+1.4035E-321 * (var_11 * (+1.6510E-315 - var_12 * -1.0010E306))));
if (comp > (var_13 - +1.7442E306)) {
  comp += (-1.3041E-38 - atan((+0.0 + +1.9261E-306 * asin(-0.0 / +1.8202E306))));
comp += var_14 + -1.1932E-171 + var_15 / (var_16 - var_17);
comp = var_18 + (var_19 + +1.7813E306);
}
for (int i=0; i < var_4; ++i) {
  comp = (+0.0 / ceill(((long double)var_20 - +1.1922E-306 / +1.0782E305 * (long double)var_21 / (long double)var_22)));
comp += var_23 / (-1.7296E306 - (var_24 / var_25));
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
  double tmp_2 = atof(argv[2]);
  double tmp_3 = atof(argv[3]);
  double tmp_4 = atof(argv[4]);
  int tmp_5 = atoi(argv[5]);
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
  double tmp_22 = atof(argv[22]);
  double tmp_23 = atof(argv[23]);
  double tmp_24 = atof(argv[24]);
  double tmp_25 = atof(argv[25]);
  double tmp_26 = atof(argv[26]);

  compute(tmp_1,tmp_2,tmp_3,tmp_4,tmp_5,tmp_6,tmp_7,tmp_8,tmp_9,tmp_10,tmp_11,tmp_12,tmp_13,tmp_14,tmp_15,tmp_16,tmp_17,tmp_18,tmp_19,tmp_20,tmp_21,tmp_22,tmp_23,tmp_24,tmp_25,tmp_26);

  return 0;
}
