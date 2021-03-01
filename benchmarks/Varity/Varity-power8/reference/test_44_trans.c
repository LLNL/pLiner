/* command----------------------------------------------------------------lassen387_54605_tests_group_3_test_3.c
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O0 -O0 test.c -lm
$ ./test_O0 -1.4646E-306 5 -1.5684E306 +0.0 +1.0785E-323 +1.3660E-307 +1.0705E305 -1.4656E305 +1.6246E-320 -1.8243E-321 +1.8079E-307 +1.5505E-294 +1.0047E305 +1.4931E305 -1.6251E305 +1.5842E-222 +0.0 -1.0456E-306 +1.6059E306
-1.4645999999999999e-306
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O3 -O3 test.c -lm
$ ./test_O3 -1.4646E-306 5 -1.5684E306 +0.0 +1.0785E-323 +1.3660E-307 +1.0705E305 -1.4656E305 +1.6246E-320 -1.8243E-321 +1.8079E-307 +1.5505E-294 +1.0047E305 +1.4931E305 -1.6251E305 +1.5842E-222 +0.0 -1.0456E-306 +1.6059E306
-6.0317099999999994e+306
--------------------------------------------------------------------------*/

/* This is a automatically generated test. Do not modify */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void compute(double comp, int var_1,double var_2,double var_3,double var_4,double var_5,double var_6,double var_7,double var_8,double var_9,double var_10,double var_11,double var_12,double var_13,double var_14,double var_15,double var_16,double var_17,double var_18) {
if ((long double)comp > ((long double)var_2 + (-1.5845E-306 * +0.0 / (long double)var_3 + -0.0))) {
  comp += (var_4 * var_5);
if (comp == fabs(floor((var_6 - var_7)))) {
  comp = (var_8 - log(var_9 * (-0.0 - var_10)));
comp = (var_11 * var_12 + (+1.2312E-280 / var_13));
}
for (int i=0; i < var_1; ++i) {
  comp = (var_14 - var_15 - var_16);
comp += (-0.0 + ldexp((var_17 - (+1.4673E306 + sin(-1.0102E179 / var_18))), 2));
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

  compute(tmp_1,tmp_2,tmp_3,tmp_4,tmp_5,tmp_6,tmp_7,tmp_8,tmp_9,tmp_10,tmp_11,tmp_12,tmp_13,tmp_14,tmp_15,tmp_16,tmp_17,tmp_18,tmp_19);

  return 0;
}
