/* command----------------------------------------------------------------lassen736_156529_tests_group_7_test_2.c
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O0 -O0 test.c -lm
$ ./test_O0 +1.6237E-307 -1.0488E129 -1.9043E-307 +0.0 -0.0 -1.4961E306 -1.6405E306 +1.2744E306 +1.9079E-42
-5.2050588112834391e-266
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O3 -O3 test.c -lm
$ ./test_O3 +1.6237E-307 -1.0488E129 -1.9043E-307 +0.0 -0.0 -1.4961E306 -1.6405E306 +1.2744E306 +1.9079E-42
nan
--------------------------------------------------------------------------*/

/* This is a automatically generated test. Do not modify */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void compute(double comp, double var_1,double var_2,double var_3,double var_4,double var_5,double var_6,double var_7,double var_8) {
double tmp_1 = +1.0001E40;
comp = tmp_1 / (-1.9214E305 + (-1.7061E-46 * sqrt(+1.7609E-307 / (+1.7977E-1 + var_1 * (var_2 + +1.3095E-318)))));
printf("%.17g\n", comp);
double tmp = var_3 / -1.0942E-310 - var_4;
printf("%.17g\n", tmp);

if (comp >= var_3 / -1.0942E-310 - var_4) {
printf("%.17g >= %.17g\n", comp, tmp);
  double tmp_2 = (var_5 + log(var_6 * var_7));
comp = tmp_2 / (var_8 / (+0.0 + -1.8805E121));
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

  compute(tmp_1,tmp_2,tmp_3,tmp_4,tmp_5,tmp_6,tmp_7,tmp_8,tmp_9);

  return 0;
}
