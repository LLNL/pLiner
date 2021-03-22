/* command----------------------------------------------------------------lassen191_36622/_tests/_group_9/_test_8.c
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O0 -O0 test.c -lm
$ ./test_O0 +1.2961E305 -1.5193E-173 -1.3987E-307 +1.8071E-288 +1.8315E110 +1.5605E-307 +0.0 +1.3095E-316 -0.0 +1.9112E305 -1.1220E-317 -1.6588E306
1.4499999999999986e+303
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O3 -O3 test.c -lm
$ ./test_O3 +1.2961E305 -1.5193E-173 -1.3987E-307 +1.8071E-288 +1.8315E110 +1.5605E-307 +0.0 +1.3095E-316 -0.0 +1.9112E305 -1.1220E-317 -1.6588E306
-0
--------------------------------------------------------------------------*/


/* This is a automatically generated test. Do not modify */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void compute(double comp, double var_1,double var_2,double var_3,double var_4,double var_5,double var_6,double var_7,double var_8,double var_9,double var_10,double var_11) {
if (comp >= (-1.3808E-66 * +1.7872E-314)) {
  comp += (-1.2816E305 + (var_1 * var_2 / var_3));
comp += sinh(cos(ldexp(sqrt(sqrt(sqrt(+1.6877E130))), 2)));
comp += (var_4 * atan(var_5 * var_6));
if (comp >= (+1.5847E306 - (var_7 / var_8 - var_9))) {
  comp += sinh(cos(+0.0));
double tmp_1 = +1.9856E-306;
comp = tmp_1 * +1.7479E-306 - (var_10 / var_11);
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

  compute(tmp_1,tmp_2,tmp_3,tmp_4,tmp_5,tmp_6,tmp_7,tmp_8,tmp_9,tmp_10,tmp_11,tmp_12);

  return 0;
}
