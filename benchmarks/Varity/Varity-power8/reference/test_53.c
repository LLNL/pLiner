/* command----------------------------------------------------------------lassen191_36623_tests_group_5_test_8.c
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O0 -O0 test.c -lm
$ ./test_O0 -0.0 5 -1.1000E55 +1.3588E-314 +1.0127E306 -1.0124E-306 +1.3235E-121 -0.0 -1.6841E-68 -1.1822E242 -0.0
-1.6841e-68
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O3 -O3 test.c -lm
$ ./test_O3 -0.0 5 -1.1000E55 +1.3588E-314 +1.0127E306 -1.0124E-306 +1.3235E-121 -0.0 -1.6841E-68 -1.1822E242 -0.0
-8.4205000000000002e-68
--------------------------------------------------------------------------*/

/* This is a automatically generated test. Do not modify */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void compute(double comp, int var_1,double var_2,double var_3,double var_4,double var_5,double var_6,double var_7,double var_8,double var_9,double var_10) {
for (int i=0; i < var_1; ++i) {
  if (comp > +0.0 - ldexp(-1.6565E37 * var_2, 2)) {
    if (comp >= sqrt(tanh((var_3 / (var_4 / var_5 + (var_6 * var_7)))))) {
      comp += (-1.1647E-310 + asin(var_8 - (+1.7015E305 / (var_9 / (-1.9883E-306 - var_10)))));
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

  compute(tmp_1,tmp_2,tmp_3,tmp_4,tmp_5,tmp_6,tmp_7,tmp_8,tmp_9,tmp_10,tmp_11);

  return 0;
}
