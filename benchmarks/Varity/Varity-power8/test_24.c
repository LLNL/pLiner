/* command----------------------------------------------------------------lassen439_81566/_tests/_group_4/_test_6.c
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O0 -O0 test.c -lm
$ ./test_O0 +1.8322E-70 -0.0 +1.9493E294 +1.5491E-259 -1.6611E306 +1.7911E173 +0.0 +1.1937E306 -0.0 -1.8638E305
1.8321999999999999e-70
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O3 -O3 test.c -lm
$ ./test_O3 +1.8322E-70 -0.0 +1.9493E294 +1.5491E-259 -1.6611E306 +1.7911E173 +0.0 +1.1937E306 -0.0 -1.8638E305
nan
--------------------------------------------------------------------------*/


/* This is a automatically generated test. Do not modify */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void compute(double comp, double var_1,double var_2,double var_3,double var_4,double var_5,double var_6,double var_7,double var_8,double var_9) {
if (comp >= -1.7022E-268 / var_1) {
  if (comp > +0.0 / pow(var_2 - var_3, var_4 + var_5)) {
    double tmp_1 = -1.5128E228;
comp += tmp_1 * cosh(ldexp(-1.6907E305 + +1.4123E305 - var_6 / +0.0 - +0.0, 2));
comp += (var_7 - var_8 * var_9);
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

  compute(tmp_1,tmp_2,tmp_3,tmp_4,tmp_5,tmp_6,tmp_7,tmp_8,tmp_9,tmp_10);

  return 0;
}
