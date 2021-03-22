/* command----------------------------------------------------------------lassen231_173925_tests_group_6_test_6.c
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O0 -O0 test.c -lm
$ ./test_O0 -1.4679E-307 5 5 +1.4818E306 +1.4193E-313 +1.8273E-307 -1.6404E-293 -1.5060E-306 -1.5480E237 -1.5024E-317
1.4674000000000001e-50
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O3 -O3 test.c -lm
$ ./test_O3 -1.4679E-307 5 5 +1.4818E306 +1.4193E-313 +1.8273E-307 -1.6404E-293 -1.5060E-306 -1.5480E237 -1.5024E-317
nan
--------------------------------------------------------------------------*/

/* This is a automatically generated test. Do not modify */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void compute(double comp, int var_1,int var_2,double var_3,double var_4,double var_5,double var_6,double var_7,double var_8,double var_9) {
for (int i=0; i < var_1; ++i) {
  comp += (var_3 / var_4 - (var_5 * log(cosh(sin(pow(-1.2826E305 - var_6, fmod(-1.9982E-306, var_7 * var_8)))))));
for (int i=0; i < var_2; ++i) {
  comp = +1.4674E-50 - -1.0495E-323 / (long double)var_9 * +1.4874E-119;
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
  int tmp_3 = atoi(argv[3]);
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
