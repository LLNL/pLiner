/* command----------------------------------------------------------------lassen370_97704/_tests/_group_4/_test_5.c
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O0 -O0 test.c -lm
$ ./test_O0 +1.2114E-307 5 5 +1.9293E306 +0.0 -1.8628E-317 -1.9360E305 -1.2220E-79 5 -1.5535E-276 +1.6306E-315 +1.3870E-312 +1.7027E306 -0.0 +1.3336E306 -1.4885E-210 -1.8679E20
1.2114e-307
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O3 -O3 test.c -lm
$ ./test_O3 +1.2114E-307 5 5 +1.9293E306 +0.0 -1.8628E-317 -1.9360E305 -1.2220E-79 5 -1.5535E-276 +1.6306E-315 +1.3870E-312 +1.7027E306 -0.0 +1.3336E306 -1.4885E-210 -1.8679E20
0
--------------------------------------------------------------------------*/

/* This is a automatically generated test. Do not modify */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void compute(double comp, int var_1,int var_2,double var_3,double var_4,double var_5,double var_6,double* var_7,int var_8,double var_9,double var_10,double var_11,double var_12,double var_13,double var_14,double var_15,double var_16) {
if (comp <= asin(tanh(+1.6220E-94 / +1.5549E198 * atan2((var_3 + var_4 + +1.7243E-306), var_5 * atan2(asin(var_6 * floor(ldexp(+1.9699E235, 2))), +1.2464E-306))))) {
  for (int i=0; i < var_1; ++i) {
    for (int i=0; i < var_2; ++i) {
      double tmp_1 = -1.0991E306;
var_7[i] = -1.9672E-307 / -1.4747E305 + (var_9 - +1.6204E-152);
comp += var_7[i] / tmp_1 / acos(sqrt((-0.0 - (var_10 / (-0.0 / var_11)))));
for (int i=0; i < var_8; ++i) {
  comp = (+1.6151E-322 * (+0.0 - +1.8874E305 - var_12));
double tmp_2 = +1.9356E-306 * cos(-1.0212E-306);
comp = tmp_2 * var_13 * ldexp(-1.4135E-307 / -1.2124E305 / -1.6879E-312, 2);
}
if (comp <= var_14 / -1.2151E306) {
  comp = cosh((-1.1497E-312 * +1.1735E-323 - var_15 * var_16 / +1.8913E-321));
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
  double tmp_6 = atof(argv[6]);
  double tmp_7 = atof(argv[7]);
  double* tmp_8 = initPointer( atof(argv[8]) );
  int tmp_9 = atoi(argv[9]);
  double tmp_10 = atof(argv[10]);
  double tmp_11 = atof(argv[11]);
  double tmp_12 = atof(argv[12]);
  double tmp_13 = atof(argv[13]);
  double tmp_14 = atof(argv[14]);
  double tmp_15 = atof(argv[15]);
  double tmp_16 = atof(argv[16]);
  double tmp_17 = atof(argv[17]);

  compute(tmp_1,tmp_2,tmp_3,tmp_4,tmp_5,tmp_6,tmp_7,tmp_8,tmp_9,tmp_10,tmp_11,tmp_12,tmp_13,tmp_14,tmp_15,tmp_16,tmp_17);

  return 0;
}
