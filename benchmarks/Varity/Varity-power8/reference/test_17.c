/* command----------------------------------------------------------------lassen425_49007_tests_group_10_test_4.c
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O0 -O0 test.c -lm
$ ./test_O0 -1.9436E-58 5 5 +1.8464E-306 -1.1772E-5 -1.7239E306 -0.0 +1.2578E-58 +1.8146E305 -1.5792E-307 +1.8937E306 -0.0 +1.9050E-306 -1.7820E-307 +1.6380E-322 -1.8687E306 +1.1639E-307 +1.9007E-307
-3.0755400000000007e+306
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O3 -O3 test.c -lm
$ ./test_O3 -1.9436E-58 5 5 +1.8464E-306 -1.1772E-5 -1.7239E306 -0.0 +1.2578E-58 +1.8146E305 -1.5792E-307 +1.8937E306 -0.0 +1.9050E-306 -1.7820E-307 +1.6380E-322 -1.8687E306 +1.1639E-307 +1.9007E-307
nan
--------------------------------------------------------------------------*/


/* This is a automatically generated test. Do not modify */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void compute(double comp, int var_1,int var_2,double var_3,double var_4,double var_5,double* var_6,double* var_7,double var_8,double var_9,double var_10,double var_11,double var_12,double var_13,double var_14,double var_15,double var_16,double var_17) {
comp += var_3 * (-1.2227E-314 - (var_4 - -1.2757E-321 - var_5));
for (int i=0; i < var_1; ++i) {
  var_6[i] = +1.4320E305;
var_7[i] = var_8 + (+1.5577E-306 / (var_9 + var_10));
comp = var_7[i] - var_6[i] * var_11 - var_12 * (var_13 / var_14);
}
for (int i=0; i < var_2; ++i) {
  comp += var_15 - (+1.3709E-322 + var_16 * +1.5595E-311 - +1.2173E306);
comp += var_17 * +1.9393E157;
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
  double* tmp_7 = initPointer( atof(argv[7]) );
  double* tmp_8 = initPointer( atof(argv[8]) );
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

  compute(tmp_1,tmp_2,tmp_3,tmp_4,tmp_5,tmp_6,tmp_7,tmp_8,tmp_9,tmp_10,tmp_11,tmp_12,tmp_13,tmp_14,tmp_15,tmp_16,tmp_17,tmp_18);

  return 0;
}
