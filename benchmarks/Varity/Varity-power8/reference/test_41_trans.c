/* command----------------------------------------------------------------lassen424_146380_tests_group_5_test_3.c
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O0 -O0 test.c -lm
$ ./test_O0 -1.3678E-39 5 5 +0.0 +1.2725E-306 +1.6797E190 -1.2498E305 -1.7609E-195 -0.0 -1.1745E305
6.7825035938370101e-21
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O3 -O3 test.c -lm
$ ./test_O3 -1.3678E-39 5 5 +0.0 +1.2725E-306 +1.6797E190 -1.2498E305 -1.7609E-195 -0.0 -1.1745E305
6.7825035938370086e-21
--------------------------------------------------------------------------*/

/* This is a automatically generated test. Do not modify */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void compute(double comp, int var_1,int var_2,double var_3,double var_4,double var_5,double var_6,double var_7,double var_8,double var_9) {
for (int i=0; i < var_1; ++i) {
  comp += fmod((-1.3542E43 + (var_3 - (+1.8027E-306 - +1.8047E-316))), var_4 / var_5);
comp += +1.1452E305 - (-0.0 + +1.6517E-321 / (-1.3593E-306 / -1.9897E-68));
comp += (var_6 * (-1.4662E-124 - (var_7 - -1.2791E-320 / var_8)));
for (int i=0; i < var_2; ++i) {
  double tmp_1 = -1.5815E305;
comp = (long double)tmp_1 / +1.9853E20 / (long double)var_9;
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
