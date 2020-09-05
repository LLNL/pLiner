/* command----------------------------------------------------------------lassen439_81565_tests_group_1_test_4.c
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O0 -O0 test.c -lm
$ ./test_O0 -1.6345E-315 +1.5539E305 -1.1615E98 +0.0 +0.0 +1.3777E61 -1.4301E-111 -1.0690E-306 -0.0 -1.8003E-307 -1.3774E305 -1.2654E-323 -1.2247E305 -0.0 +1.1950E-306 -0.0 -1.6139E306 +1.2291E-323 -1.1982E-322 +1.0388E-307 -1.1618E306 +1.5091E-306 +1.0140E-319 +1.2503E-307
-1.6344999998478317e-315
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O3 -O3 test.c -lm
$ ./test_O3 -1.6345E-315 +1.5539E305 -1.1615E98 +0.0 +0.0 +1.3777E61 -1.4301E-111 -1.0690E-306 -0.0 -1.8003E-307 -1.3774E305 -1.2654E-323 -1.2247E305 -0.0 +1.1950E-306 -0.0 -1.6139E306 +1.2291E-323 -1.1982E-322 +1.0388E-307 -1.1618E306 +1.5091E-306 +1.0140E-319 +1.2503E-307
1.3776999999999999e+61
--------------------------------------------------------------------------*/

/* This is a automatically generated test. Do not modify */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void compute(double comp, double var_1,double var_2,double var_3,double var_4,double var_5,double var_6,double var_7,double var_8,double var_9,double var_10,double var_11,double var_12,double var_13,double var_14,double var_15,double var_16,double var_17,double var_18,double var_19,double var_20,double var_21,double var_22,double var_23) {
double tmp_1 = -1.2482E-57 - var_1 * var_2 * -0.0;
printf("%.17g\n", tmp_1);
if (comp >= -1.2482E-57 - var_1 * var_2 * -0.0) {
   printf("%.17g >= %.17g\n", comp, tmp_1);
  if (comp <= var_3 - var_4) {
    comp = (+1.8155E-323 + var_5 + var_6 / var_7 * var_8);
if (comp == var_9 * (+1.2906E-318 - (var_10 / var_11))) {
  comp += (var_12 + (var_13 / var_14 - (var_15 / var_16)));
}
if (comp > (-1.3331E-311 * tanh((var_17 + var_18 + var_19 / acos(atan((-1.0997E306 / fmod(-1.9139E-316 * -1.5128E-315, (var_20 / (+1.2580E-307 * atan(+1.1374E-72 - asin(var_21 - var_22 - log(+1.1744E-319 - fabs(+1.5959E305 + -1.0077E-307)))))))))))))) {
  comp += +1.0999E-311 / (+1.7373E-307 + (-1.0443E306 - var_23));
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
  double tmp_17 = atof(argv[17]);
  double tmp_18 = atof(argv[18]);
  double tmp_19 = atof(argv[19]);
  double tmp_20 = atof(argv[20]);
  double tmp_21 = atof(argv[21]);
  double tmp_22 = atof(argv[22]);
  double tmp_23 = atof(argv[23]);
  double tmp_24 = atof(argv[24]);

  compute(tmp_1,tmp_2,tmp_3,tmp_4,tmp_5,tmp_6,tmp_7,tmp_8,tmp_9,tmp_10,tmp_11,tmp_12,tmp_13,tmp_14,tmp_15,tmp_16,tmp_17,tmp_18,tmp_19,tmp_20,tmp_21,tmp_22,tmp_23,tmp_24);

  return 0;
}
