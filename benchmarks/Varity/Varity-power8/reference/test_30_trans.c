/* command----------------------------------------------------------------lassen743_26845/_tests/_group_1/_test_5.c
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O0 -O0 test.c -lm
$ ./test_O0 -1.3465E-306 5 +1.3639E306 -0.0 -1.6624E-306 -1.3818E-70 +1.8796E141 +1.1151E260 +1.9698E306 -1.0313E126
inf
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O3 -O3 test.c -lm
$ ./test_O3 -1.3465E-306 5 +1.3639E306 -0.0 -1.6624E-306 -1.3818E-70 +1.8796E141 +1.1151E260 +1.9698E306 -1.0313E126
nan
--------------------------------------------------------------------------*/


/* This is a automatically generated test. Do not modify */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void compute(double comp, int var_1,double var_2,double var_3,double var_4,double var_5,double var_6,double var_7,double var_8,double var_9) {
if (comp < (+1.0302E-241 * var_2 + var_3)) {
  for (int i=0; i < var_1; ++i) {
    comp += ldexp((var_4 + var_5), 2);
double tmp_1 = (+1.5294E-189 + +1.4216E-306);
long double comp_22_22_H = comp;
comp_22_22_H += (long double)tmp_1 + ((long double)var_6 * +1.8145E-321 * sqrtl(((long double)var_7 - ((long double)var_8 / sinl((-0.0 / (+1.0558E306 + (long double)var_9 * +1.0932E306 / -1.5610E-317)))))));comp = comp_22_22_H;

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
