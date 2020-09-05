/* command----------------------------------------------------------------lassen321_161435_tests_group_7_test_1.c
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O0 -O0 test.c -lm
$ ./test_O0 -1.8008E306 5 -1.0369E-322 +1.4478E-306 +1.3644E-319 -1.7613E-306 +1.1657E305 -1.7885E-306 -1.5200E7
15200000
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O3 -O3 test.c -lm
$ ./test_O3 -1.8008E306 5 -1.0369E-322 +1.4478E-306 +1.3644E-319 -1.7613E-306 +1.1657E305 -1.7885E-306 -1.5200E7
nan
--------------------------------------------------------------------------*/

/* This is a automatically generated test. Do not modify */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void compute(double comp, int var_1,double var_2,double var_3,double var_4,double var_5,double var_6,double var_7,double var_8) {
for (int i=0; i < var_1; ++i) {
  comp = (-1.6870E306 + cosh(+1.5538E-314));
comp += exp(+1.7529E305 + (var_2 / -0.0));
if (comp > tanh(sinh((+1.7152E-314 - var_3 / +0.0 + var_4 * var_5)))) {
  comp = var_6 + sin(ldexp((-1.3235E-319 / -1.4460E-315 + -1.7034E-307 - +1.8283E305), 2));
double tmp_1 = -1.3240E-124;
comp = tmp_1 + (var_7 + +1.2595E-310 - -1.2088E-307 - var_8);
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

  compute(tmp_1,tmp_2,tmp_3,tmp_4,tmp_5,tmp_6,tmp_7,tmp_8,tmp_9);

  return 0;
}
