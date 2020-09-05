/* command----------------------------------------------------------------lassen320_3047_tests_group_7_test_10.c
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O0 -O0 test.c -lm
$ ./test_O0 +1.3961E-306 5 -1.5754E-322 +1.6287E-133 -1.0328E306 +1.8535E306 +1.0257E-134
1.3961e-306
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O3 -O3 test.c -lm
$ ./test_O3 +1.3961E-306 5 -1.5754E-322 +1.6287E-133 -1.0328E306 +1.8535E306 +1.0257E-134
nan
--------------------------------------------------------------------------*/

/* This is a automatically generated test. Do not modify */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void compute(double comp, int var_1,double var_2,double var_3,double var_4,double var_5,double var_6) {
 long double comp_H = comp;
 long double var_2_H = var_2;
 long double var_3_H = var_3;
 long double var_4_H = var_4;
 long double var_5_H = var_5;
 long double var_6_H = var_6;
if (comp_H > (+0.0 * cosl(-0.0))) {
  if (comp_H <= logl(-1.6392E-307)) {
    for (int i=0; i < var_1; ++i) {
      comp_H += (var_2_H * -0.0);
comp_H = (-1.3629E-34 / +0.0 / (+1.9634E-312 - -1.0152E305));
comp_H += (var_3_H + (-1.8425E305 / ldexpl(-1.0035E-320 - -1.7147E-57, 2)));
if (comp_H <= (+1.6356E-299 + (var_4_H - -1.7924E306))) {
  long double tmp_1 = +0.0;
long double tmp_2 = -1.5104E262;
comp_H += tmp_2 - tmp_1 / (var_5_H / (-1.9213E306 * var_6_H));
}
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

  compute(tmp_1,tmp_2,tmp_3,tmp_4,tmp_5,tmp_6,tmp_7);

  return 0;
}
