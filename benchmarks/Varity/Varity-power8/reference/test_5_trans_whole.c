/* command---------------------------------------------------------------- lassen269_103559/_tests/_group_2/_test_7.c
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O0 -O0 test.c -lm
$ ./test_O0 +1.2838E-190 5 -1.3864E-322 +1.6500E166 -0.0 -1.7519E-306 -0.0 +1.4245E201 +1.8343E-296 -1.2824E-316 -1.2608E305
nan
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O3 -O3 test.c -lm
$ ./test_O3 +1.2838E-190 5 -1.3864E-322 +1.6500E166 -0.0 -1.7519E-306 -0.0 +1.4245E201 +1.8343E-296 -1.2824E-316 -1.2608E305
inf
--------------------------------------------------------------------------*/

/* This is a automatically generated test. Do not modify */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void compute(double comp, int var_1,double var_2,double var_3,double var_4,double var_5,double var_6,double var_7,double var_8,double var_9,double var_10) {
 long double comp_H = comp;
 long double var_2_H = var_2;
 long double var_3_H = var_3;
 long double var_4_H = var_4;
 long double var_5_H = var_5;
 long double var_6_H = var_6;
 long double var_7_H = var_7;
 long double var_8_H = var_8;
 long double var_9_H = var_9;
 long double var_10_H = var_10;
for (int i=0; i < var_1; ++i) {
  comp_H = var_2_H / -1.5625E-307 / -0.0 * -0.0;
  printf("%.17Lg\n", comp_H);
comp_H += +0.0 - var_3_H - (var_4_H + var_5_H);
comp_H += powl(var_6_H * (var_7_H - var_8_H), +1.4347E-317 + var_9_H + log10l((-1.5649E-306 / (var_10_H * (-1.2860E-307 / (-1.3199E-306 * +1.0495E238))))));
}
  printf("%.17Lg\n", comp_H);

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

  compute(tmp_1,tmp_2,tmp_3,tmp_4,tmp_5,tmp_6,tmp_7,tmp_8,tmp_9,tmp_10,tmp_11);

  return 0;
}
