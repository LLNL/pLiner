/* command---------------------------------------------------------------lassen611_75649/_tests/_group_4/_test_7.c
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O0 -O0 test.c -lm
$ ./test_O0 +1.1836E-307 -1.8156E-311 +0.0 +0.0 +1.3915E-307 
-0.0013508444125044853
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O3 -O3 test.c -lm
$ ./test_O3 +1.1836E-307 -1.8156E-311 +0.0 +0.0 +1.3915E-307
1.1836e-307
--------------------------------------------------------------------------*/


/* This is a automatically generated test. Do not modify */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void compute(double comp, double var_1,double var_2,double var_3,double var_4) {
if (comp > var_1 / (var_2 + atan2(var_3 / floor(exp(-1.0614E-306)), sinh(+1.8209E-5)))) {
  comp = (-1.8797E-310 / (var_4 + -0.0));
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

  compute(tmp_1,tmp_2,tmp_3,tmp_4,tmp_5);

  return 0;
}
