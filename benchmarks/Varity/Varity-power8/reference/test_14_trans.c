/* command----------------------------------------------------------------lassen93_127599/_tests/_group_8/_test_2.c
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O0 -O0 test.c -lm
$ ./test_O0 +0.0 -1.6872E-314 -1.5098E95 -1.1588E-178 +1.7369E-316 -1.5191E192 +1.8826E22 -0.0 -1.8297E-315 +1.3549E-318 -1.4453E-35 -0.0 -1.5098E-307 -1.5442E305 -1.9858E-321 +1.3499E305
inf
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O3 -O3 test.c -lm
$ ./test_O3 +0.0 -1.6872E-314 -1.5098E95 -1.1588E-178 +1.7369E-316 -1.5191E192 +1.8826E22 -0.0 -1.8297E-315 +1.3549E-318 -1.4453E-35 -0.0 -1.5098E-307 -1.5442E305 -1.9858E-321 +1.3499E305
nan
--------------------------------------------------------------------------*/

/* This is a automatically generated test. Do not modify */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void compute(double comp, double var_1,double var_2,double var_3,double var_4,double var_5,double var_6,double var_7,double var_8,double var_9,double var_10,double var_11,double var_12,double var_13,double var_14,double var_15) {
if (comp == (-1.1979E-316 * var_1)) {
  double tmp_1 = -1.5061E306;
comp += tmp_1 - (+1.9048E306 / (-1.9599E-320 / -1.6682E-307 - var_2));
long double comp_20_20_H = comp;
comp_20_20_H += -1.9057E305 / atanl((long double)var_3 / expl(powl((+1.5489E-176 - +1.4051E-313 / -0.0), (long double)var_4 / (long double)var_5)));comp = comp_20_20_H;

if (comp < (var_6 / var_7 + log10((var_8 + (-1.3248E-315 + cos((-1.2351E-307 + (-1.7342E-307 * var_9)))))))) {
  double tmp_2 = -1.5757E-306 / -1.8672E71 - var_10 - var_11;
double tmp_3 = (+0.0 + var_12 / ldexp((+0.0 / var_13), 2));
comp += tmp_3 + tmp_2 + (var_14 * (var_15 + floor((-1.2045E-264 - -1.0781E306))));
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
  double tmp_11 = atof(argv[11]);
  double tmp_12 = atof(argv[12]);
  double tmp_13 = atof(argv[13]);
  double tmp_14 = atof(argv[14]);
  double tmp_15 = atof(argv[15]);
  double tmp_16 = atof(argv[16]);

  compute(tmp_1,tmp_2,tmp_3,tmp_4,tmp_5,tmp_6,tmp_7,tmp_8,tmp_9,tmp_10,tmp_11,tmp_12,tmp_13,tmp_14,tmp_15,tmp_16);

  return 0;
}
