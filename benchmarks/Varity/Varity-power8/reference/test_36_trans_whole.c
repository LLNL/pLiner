/* command----------------------------------------------------------------lassen321_161436_tests_group_3_test_5.c
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O0 -O0 test.c -lm
$ ./test_O0 -1.8403E279 5 +1.2489E305 -0.0 +1.7353E306 +1.9286E70 +1.7692E-306 -0.0 -1.8963E-306
nan
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O3 -O3 test.c -lm
$ ./test_O3 -1.8403E279 5 +1.2489E305 -0.0 +1.7353E306 +1.9286E70 +1.7692E-306 -0.0 -1.8963E-306
-inf
--------------------------------------------------------------------------*/


/* This is a automatically generated test. Do not modify */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void compute(double comp, int var_1,double var_2,double var_3,double* var_4,double var_5,double var_6,double var_7,double var_8) {
 long double comp_H = comp;
 long double var_2_H = var_2;
 long double var_3_H = var_3;
 long double var_5_H = var_5;
 long double var_6_H = var_6;
 long double var_7_H = var_7;
 long double var_8_H = var_8;
comp_H = var_2_H + coshl(-0.0 * -1.7172E305);
comp_H = +1.3263E-306 - var_3_H * -1.2187E-319 / -1.2404E-307;
for (int i=0; i < var_1; ++i) {
  var_4[i] = var_5_H / fabsl(-0.0 * (+0.0 + atanhl(-0.0 / (var_6_H - logl((-1.4635E-314 - var_7_H / +1.1101E-312 / (+1.4555E306 * var_8_H)))))));
long double tmp_1 = (-1.3978E-323 - (+1.6057E224 * (-1.0390E-307 + +1.9587E-307)));
comp_H = tmp_1 - (long double)var_4[i] + (+1.0693E-306 + (+1.9925E-311 * -1.5648E-307 * -0.0));
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
  double* tmp_5 = initPointer( atof(argv[5]) );
  double tmp_6 = atof(argv[6]);
  double tmp_7 = atof(argv[7]);
  double tmp_8 = atof(argv[8]);
  double tmp_9 = atof(argv[9]);

  compute(tmp_1,tmp_2,tmp_3,tmp_4,tmp_5,tmp_6,tmp_7,tmp_8,tmp_9);

  return 0;
}
