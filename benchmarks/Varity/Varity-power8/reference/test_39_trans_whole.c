/* command----------------------------------------------------------------lassen320_3047_tests_group_6_test_7.c
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O0 -O0 test.c -lm
$ ./test_O0 +1.5590E-306 +0.0 +0.0 -1.4801E305 +1.8670E-307 -1.4230E-307 +0.0 +1.9887E-320 +1.8139E-306 +1.1686E306 +1.7314E305
1.3723000001654872e-306
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O3 -O3 test.c -lm
$ ./test_O3 +1.5590E-306 +0.0 +0.0 -1.4801E305 +1.8670E-307 -1.4230E-307 +0.0 +1.9887E-320 +1.8139E-306 +1.1686E306 +1.7314E305
1.5590000000000001e-306
--------------------------------------------------------------------------*/

/* This is a automatically generated test. Do not modify */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void compute(double comp, double var_1,double var_2,double var_3,double var_4,double var_5,double var_6,double var_7,double var_8,double var_9,double var_10) {
 long double comp_H = comp;
 long double var_1_H = var_1;
 long double var_2_H = var_2;
 long double var_3_H = var_3;
 long double var_4_H = var_4;
 long double var_5_H = var_5;
 long double var_6_H = var_6;
 long double var_7_H = var_7;
 long double var_8_H = var_8;
 long double var_9_H = var_9;
 long double var_10_H = var_10;
if (comp_H > (var_1_H / +1.4859E-310 + (var_2_H * atan2l(var_3_H / -1.8131E-319, -1.0247E305)))) {
  comp_H += (var_4_H * (var_5_H - powl(var_6_H * +0.0 / sinl((var_7_H * +1.5574E204 - sinhl(+0.0))), fabsl(+0.0))));
comp_H += atanl((+1.9531E-310 * (+1.3782E-312 / (-1.8733E-307 + sinhl(var_8_H + ldexpl(+1.6580E-318, 2))))));
if (comp_H >= ldexpl(+1.5912E200, 2)) {
  comp_H += var_9_H - -0.0 * (var_10_H / -1.3628E154);
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
  double tmp_2 = atof(argv[2]);
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
