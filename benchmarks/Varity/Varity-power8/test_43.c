/* command----------------------------------------------------------------lassen205_18657_tests_group_3_test_7.c
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O0 -O0 test.c -lm
$ ./test_O0 -1.2369E-88 5 +1.1363E-307 -1.8711E-50 +0.0 -1.1423E-307 -1.1175E-86 -0.0 -1.5849E7 -0.0 +1.3836E-307 +1.6902E-307
8.4630153700128806e-13
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O3 -O3 test.c -lm
$ ./test_O3 -1.2369E-88 5 +1.1363E-307 -1.8711E-50 +0.0 -1.1423E-307 -1.1175E-86 -0.0 -1.5849E7 -0.0 +1.3836E-307 +1.6902E-307
8.4630153678381065e-13
--------------------------------------------------------------------------*/

/* This is a automatically generated test. Do not modify */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void compute(double comp, int var_1,double var_2,double var_3,double var_4,double var_5,double var_6,double var_7,double var_8,double var_9,double var_10,double var_11) {
double tmp_1 = +1.7333E-314;
comp += tmp_1 - +0.0 - var_2 - -1.0739E-310 * (var_3 + var_4);
for (int i=0; i < var_1; ++i) {
  comp += (-1.4742E-306 - var_5 - asin(-1.5989E-310 + -1.3994E306 / (+1.9726E305 / var_6)));
}
if (comp < (-1.8843E-306 - (var_7 + floor((var_8 + -1.4664E-322 - -1.8196E306 * var_9))))) {
  comp += (-0.0 / (+0.0 - var_10));
comp = (+1.4304E-319 / var_11);
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

  compute(tmp_1,tmp_2,tmp_3,tmp_4,tmp_5,tmp_6,tmp_7,tmp_8,tmp_9,tmp_10,tmp_11,tmp_12);

  return 0;
}
