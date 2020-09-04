/* command----------------------------------------------------------------lassen736_156529_tests_group_7_test_2.c
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O0 -O0 test.c -lm
$ ./test_O0 +1.6237E-307 -1.0488E129 -1.9043E-307 +0.0 -0.0 -1.4961E306 -1.6405E306 +1.2744E306 +1.9079E-42
-5.2050588112834391e-266
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O3 -O3 test.c -lm
$ ./test_O3 +1.6237E-307 -1.0488E129 -1.9043E-307 +0.0 -0.0 -1.4961E306 -1.6405E306 +1.2744E306 +1.9079E-42
nan
--------------------------------------------------------------------------*/

/* This is a automatically generated test. Do not modify */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void compute(double comp, double var_1,double var_2,double var_3,double var_4,double var_5,double var_6,double var_7,double var_8) {
 long double comp_H = comp;
 long double var_1_H = var_1;
 long double var_2_H = var_2;
 long double var_3_H = var_3;
 long double var_4_H = var_4;
 long double var_5_H = var_5;
 long double var_6_H = var_6;
 long double var_7_H = var_7;
 long double var_8_H = var_8;
long double tmp_1 = +1.0001E40L;
comp_H = tmp_1 / (-1.9214E305L + (-1.7061E-46L * sqrtl(+1.7609E-307L / (+1.7977E-1L + var_1_H * (var_2_H + +1.3095E-318L)))));
if (comp_H >= var_3_H / -1.0942E-310L - var_4_H) {
  long double tmp_2 = (var_5_H + logl(var_6_H * var_7_H));
comp_H = tmp_2 / (var_8_H / (+0.0L + -1.8805E121L));
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

  compute(tmp_1,tmp_2,tmp_3,tmp_4,tmp_5,tmp_6,tmp_7,tmp_8,tmp_9);

  return 0;
}
