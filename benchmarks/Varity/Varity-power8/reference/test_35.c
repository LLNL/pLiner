/* command----------------------------------------------------------------lassen806_85216/_tests/_group_10/_test_2.c
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O0 -O0 test.c -lm
$ ./test_O0 +1.8510E306 5 +0.0 +0.0 -1.7772E-306 -1.6844E-306 -1.0217E-307 +1.3952E-307 +1.0507E-317 -0.0
inf
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O3 -O3 test.c -lm
$ ./test_O3 +1.8510E306 5 +0.0 +0.0 -1.7772E-306 -1.6844E-306 -1.0217E-307 +1.3952E-307 +1.0507E-317 -0.0
nan
--------------------------------------------------------------------------*/


/* This is a automatically generated test. Do not modify */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void compute(double comp, int var_1,double var_2,double var_3,double var_4,double var_5,double var_6,double var_7,double var_8,double var_9) {
for (int i=0; i < var_1; ++i) {
  comp = (var_2 * var_3 - (var_4 + var_5));
if (comp < (var_6 * (var_7 - var_8 / -1.6747E306 + -1.3789E305))) {
  comp = +1.0485E305 / (+0.0 + (-0.0 - var_9));
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
  double tmp_3 = atof(argv[3]);
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
