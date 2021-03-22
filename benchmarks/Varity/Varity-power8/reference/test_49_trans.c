/* command----------------------------------------------------------------lassen262_170435_tests_group_3_test_4.c
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O0 -O0 test.c -lm
$ ./test_O0 +0.0 +0.0 +1.3074E305 +0.0 +1.9607E-313 -1.6176E-311
-inf
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O3 -O3 test.c -lm
$ ./test_O3 +0.0 +0.0 +1.3074E305 +0.0 +1.9607E-313 -1.6176E-311
nan
--------------------------------------------------------------------------*/
/* This is a automatically generated test. Do not modify */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void compute(double comp, double var_1,double var_2,double var_3,double var_4,double var_5) {
double tmp_1 = +1.1914E-81;
double tmp_2 = (+1.4602E273 + (var_1 + var_2 - (var_3 - -0.0)));
comp = (long double)tmp_2 * (long double)tmp_1 / ((long double)var_4 + ((long double)var_5 - +1.9535E-238));
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
  double tmp_5 = atof(argv[5]);
  double tmp_6 = atof(argv[6]);

  compute(tmp_1,tmp_2,tmp_3,tmp_4,tmp_5,tmp_6);

  return 0;
}
