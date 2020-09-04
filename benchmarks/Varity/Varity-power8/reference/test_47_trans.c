/* command----------------------------------------------------------------lassen789_104131_tests_group_10_test_7.c
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O0 -O0 test.c -lm
$ ./test_O0 -1.4319E-321 5 -0.0 -1.8153E-318 -1.6686E306 +1.7972E146 -0.0 +1.2916E-307 +1.8555E-307 -0.0 -1.3856E305 -1.2728E-203 -1.4727E-319 -1.2808E128 -1.4069E-306
1.98013296e+193
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O3 -O3 test.c -lm
$ ./test_O3 -1.4319E-321 5 -0.0 -1.8153E-318 -1.6686E306 +1.7972E146 -0.0 +1.2916E-307 +1.8555E-307 -0.0 -1.3856E305 -1.2728E-203 -1.4727E-319 -1.2808E128 -1.4069E-306
nan
--------------------------------------------------------------------------*/

/* This is a automatically generated test. Do not modify */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void compute(double comp, int var_1,double var_2,double var_3,double var_4,double* var_5,double var_6,double var_7,double var_8,double var_9,double var_10,double var_11,double var_12,double var_13,double var_14) {
comp += var_2 - -1.6421E-307;
comp = -1.7848E-323 * var_3 / tanh(-1.6352E-66 - -0.0 * var_4 / -1.0156E-97);
for (int i=0; i < var_1; ++i) {
  double tmp_1 = +1.7894E-307;
var_5[i] = +1.0098E167;
long double comp_22_22_H = comp;
comp_22_22_H += (long double)var_5[i] + (long double)tmp_1 / ((long double)var_6 * cosl((long double)var_7 / (long double)var_8 + (long double)var_9 - -1.1317E-311));comp = comp_22_22_H;

}
if (comp == -1.2083E306 / +1.9580E-306) {
  comp = (-1.8499E-113 * (-1.0704E306 - +0.0 / fmod(var_10 - (+1.8254E-307 - var_11), -1.0382E-306)));
comp += asin(+1.7251E-307 * var_12 * var_13);
comp += (+0.0 / var_14);
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
  double* tmp_6 = initPointer( atof(argv[6]) );
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
