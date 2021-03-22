/* command----------------------------------------------------------------lassen125_48342/_tests/_group_6/_test_8.c
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O0 -O0 test.c -lm
$ ./test_O0 +1.4108E305 -1.0785E-306 -1.5363E305 -1.7355E-46 +1.2529E-311 +1.0789E305 +1.6772E-321 -0.0 -1.6480E-315 +1.8011E-306 -1.2776E-306 -0.0 -1.0163E306 +0.0
-1.5362999999999999e+305
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O3 -O3 test.c -lm
$ ./test_O3 +1.4108E305 -1.0785E-306 -1.5363E305 -1.7355E-46 +1.2529E-311 +1.0789E305 +1.6772E-321 -0.0 -1.6480E-315 +1.8011E-306 -1.2776E-306 -0.0 -1.0163E306 +0.0
nan
--------------------------------------------------------------------------*/


/* This is a automatically generated test. Do not modify */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void compute(double comp, double var_1,double var_2,double var_3,double var_4,double var_5,double var_6,double var_7,double var_8,double var_9,double var_10,double var_11,double var_12,double var_13) {
comp = -1.5894E-306 * (+1.0887E305 * var_1);
long double comp_19_19_H = comp;
comp_19_19_H += (long double)var_2 + ((long double)var_3 / fmodl(-1.0108E-306 + fabsl((long double)var_4 - sinhl((-1.8897E-182 / (long double)var_5))), +1.1624E-311 / -1.8791E-314 * ((long double)var_6 + (long double)var_7)));comp = comp_19_19_H;

if ((long double)comp >= (long double)var_8 / (-1.5737E306 - sinl((long double)var_9 + +1.2368E305 - (-1.9849E-306 + (long double)var_10)))) {
  comp += -1.5249E-290 / (var_11 * -1.9369E-237 / atan(var_12 - -1.9444E306));
double tmp_1 = +1.1528E2;
comp += tmp_1 / (-1.1289E-14 * (-1.9234E-307 * var_13));
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

  compute(tmp_1,tmp_2,tmp_3,tmp_4,tmp_5,tmp_6,tmp_7,tmp_8,tmp_9,tmp_10,tmp_11,tmp_12,tmp_13,tmp_14);

  return 0;
}
