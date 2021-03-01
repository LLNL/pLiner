/* command----------------------------------------------------------------lassen449_79598/_tests/_group_6/_test_2.c
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O0 -O0 test.c -lm
$ ./test_O0 +1.7572E305 -1.3329E305 -1.0461E-59 -1.9195E-312
1.7572000000000001e+305
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O3 -O3 test.c -lm
$ ./test_O3 +1.7572E305 -1.3329E305 -1.0461E-59 -1.9195E-312
nan
--------------------------------------------------------------------------*/


/* This is a automatically generated test. Do not modify */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void compute(double comp, double var_1,double var_2,double var_3) {
if (comp >= +1.8699E-95 + var_1) {
  double tmp_1 = +1.2269E306;
double tmp_2 = +1.6846E-109;
comp += tmp_2 * tmp_1 + var_2 / var_3;
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

  compute(tmp_1,tmp_2,tmp_3,tmp_4);

  return 0;
}
