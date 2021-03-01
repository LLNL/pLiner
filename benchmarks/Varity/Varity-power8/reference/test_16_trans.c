/* command----------------------------------------------------------------lassen205_18655_tests_group_4_test_2.c
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O0 -O0 test.c -lm
$ ./test_O0 +1.9097E306 5 5 +1.9048E306 -1.5777E-307 5 5 -0.0 +1.1982E-38 -1.7359E306 +0.0 +1.2300E305 +1.9983E-316 -1.2151E305 +1.5847E79 -1.5725E-242 -1.0469E-323 -1.9755E-306 -1.2973E-307 
-inf
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O3 -O3 test.c -lm
$ ./test_O3 +1.9097E306 5 5 +1.9048E306 -1.5777E-307 5 5 -0.0 +1.1982E-38 -1.7359E306 +0.0 +1.2300E305 +1.9983E-316 -1.2151E305 +1.5847E79 -1.5725E-242 -1.0469E-323 -1.9755E-306 -1.2973E-307 
nan
--------------------------------------------------------------------------*/


/* This is a automatically generated test. Do not modify */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void compute(double comp, int var_1,int var_2,double var_3,double var_4,int var_5,int var_6,double var_7,double var_8,double var_9,double var_10,double* var_11,double* var_12,double var_13,double var_14,double var_15,double var_16,double var_17,double var_18) {
for (int i=0; i < var_1; ++i) {
  if (comp > (var_3 + var_4)) {
    for (int i=0; i < var_2; ++i) {
      comp += tanh(var_7 * +1.4761E-307 - var_8);
comp += var_9 + +1.9376E306 * var_10;
for (int i=0; i < var_5; ++i) {
  var_11[i] = sin((var_13 / -1.7377E306));
var_12[i] = sin((var_14 + +1.0457E-307 / var_15));
comp = var_12[i] - var_11[i] + -1.1276E-307 + +0.0;
}
for (int i=0; i < var_6; ++i) {
  comp = +1.5303E306 - ((long double)var_16 / (-0.0 / (long double)var_17 * (long double)var_18));
}
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
  int tmp_3 = atoi(argv[3]);
  double tmp_4 = atof(argv[4]);
  double tmp_5 = atof(argv[5]);
  int tmp_6 = atoi(argv[6]);
  int tmp_7 = atoi(argv[7]);
  double tmp_8 = atof(argv[8]);
  double tmp_9 = atof(argv[9]);
  double tmp_10 = atof(argv[10]);
  double tmp_11 = atof(argv[11]);
  double* tmp_12 = initPointer( atof(argv[12]) );
  double* tmp_13 = initPointer( atof(argv[13]) );
  double tmp_14 = atof(argv[14]);
  double tmp_15 = atof(argv[15]);
  double tmp_16 = atof(argv[16]);
  double tmp_17 = atof(argv[17]);
  double tmp_18 = atof(argv[18]);
  double tmp_19 = atof(argv[19]);

  compute(tmp_1,tmp_2,tmp_3,tmp_4,tmp_5,tmp_6,tmp_7,tmp_8,tmp_9,tmp_10,tmp_11,tmp_12,tmp_13,tmp_14,tmp_15,tmp_16,tmp_17,tmp_18,tmp_19);

  return 0;
}
