/* command----------------------------------------------------------------lassen411_94879_tests_group_10_test_2.c
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O0 -O0 test.c -lm
$ ./test_O0 +1.5594E-323 -1.6270E-323 -1.6886E-187 +1.9938E-317 -1.5465E-313 -1.2740E-313 -0.0 +1.3516E-317 +1.7867E-307 +0.0
7.5647846381198691e-11
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O3 -O3 test.c -lm
$ ./test_O3 +1.5594E-323 -1.6270E-323 -1.6886E-187 +1.9938E-317 -1.5465E-313 -1.2740E-313 -0.0 +1.3516E-317 +1.7867E-307 +0.0
7.5647846346388256e-11
--------------------------------------------------------------------------*/


/* This is a automatically generated test. Do not modify */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void compute(double comp, double var_1,double var_2,double var_3,double var_4,double var_5,double var_6,double var_7,double var_8,double var_9) {
if (comp < tanh((var_1 - -0.0 + +1.3242E191))) {
  double tmp_1 = -1.9559E72;
double tmp_2 = -1.7167E-307 + var_2 + var_3;
comp += tmp_2 + tmp_1 / (-1.2108E-114 + +1.3503E222 * -1.7968E305);
if (comp > -1.4684E26 + var_4 + var_5) {
  comp = (long double)var_6 + (long double)var_7 / (long double)var_8;
comp += var_9 + (+1.5359E-307 - -1.1423E-314);
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
  double tmp_5 = atof(argv[5]);
  double tmp_6 = atof(argv[6]);
  double tmp_7 = atof(argv[7]);
  double tmp_8 = atof(argv[8]);
  double tmp_9 = atof(argv[9]);
  double tmp_10 = atof(argv[10]);

  compute(tmp_1,tmp_2,tmp_3,tmp_4,tmp_5,tmp_6,tmp_7,tmp_8,tmp_9,tmp_10);

  return 0;
}
