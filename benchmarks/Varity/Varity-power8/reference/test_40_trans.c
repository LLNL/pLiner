/* command----------------------------------------------------------------lassen411_94880_tests_group_8_test_6.c
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O0 -O0 test.c -lm 
$ ./test_O0 -1.3049E179 5 5 -1.8151E-321 +1.6352E-307 +1.6170E306 -1.8910E100 -1.1505E-316 -1.9522E306 -1.7795E306 +1.0391E306 +1.2187E-93 +1.7160E-307 -1.6570E-307 -1.4194E-320 -1.3571E-307 +1.1927E305 +1.0727E-227 -1.3157E-313 
-1.3049000000000001e+179
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O3 -O3 test.c -lm
$ ./test_O3 -1.3049E179 5 5 -1.8151E-321 +1.6352E-307 +1.6170E306 -1.8910E100 -1.1505E-316 -1.9522E306 -1.7795E306 +1.0391E306 +1.2187E-93 +1.7160E-307 -1.6570E-307 -1.4194E-320 -1.3571E-307 +1.1927E305 +1.0727E-227 -1.3157E-313
nan
--------------------------------------------------------------------------*/

/* This is a automatically generated test. Do not modify */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void compute(double comp, int var_1,int var_2,double var_3,double var_4,double var_5,double var_6,double var_7,double var_8,double* var_9,double* var_10,double var_11,double var_12,double var_13,double* var_14,double var_15,double var_16,double var_17,double var_18) {
if ((long double)comp >= -1.3209E288 / (long double)var_3 * (+1.4022E306 * (long double)var_4)) {
  double tmp_1 = (var_5 + var_6 + -1.9386E-311 * +1.1195E-307);
comp = tmp_1 - -1.2284E195 - (var_7 - (+1.9092E-307 - +1.1087E197));
comp += sin(var_8 + -1.9662E-306 - +1.3836E-310);
for (int i=0; i < var_1; ++i) {
  var_9[i] = (-1.2630E-319 + (+1.3782E306 - ldexp((+1.7694E306 * (var_11 / atan(-1.6868E306))), 2)));
var_10[i] = -1.0281E-307;
comp += var_10[i] / var_9[i] / (-1.5748E-307 + (var_12 * var_13 * (-0.0 - -1.7916E305)));
}
for (int i=0; i < var_2; ++i) {
  var_14[i] = cos((var_15 / var_16 * (+1.8116E-314 / +1.9488E305 * +1.7207E-57)));
comp = var_14[i] * var_17 / var_18;
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
  double* tmp_10 = initPointer( atof(argv[10]) );
  double* tmp_11 = initPointer( atof(argv[11]) );
  double tmp_12 = atof(argv[12]);
  double tmp_13 = atof(argv[13]);
  double tmp_14 = atof(argv[14]);
  double* tmp_15 = initPointer( atof(argv[15]) );
  double tmp_16 = atof(argv[16]);
  double tmp_17 = atof(argv[17]);
  double tmp_18 = atof(argv[18]);
  double tmp_19 = atof(argv[19]);

  compute(tmp_1,tmp_2,tmp_3,tmp_4,tmp_5,tmp_6,tmp_7,tmp_8,tmp_9,tmp_10,tmp_11,tmp_12,tmp_13,tmp_14,tmp_15,tmp_16,tmp_17,tmp_18,tmp_19);

  return 0;
}
