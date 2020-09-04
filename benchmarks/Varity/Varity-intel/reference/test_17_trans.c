//quartz2962_37414/_tests/_group_9/_test_10.c
//-1.3698E-320 5 +1.6796E-307 +1.5688E-318 -1.5728E306 +1.3621E35 -1.8164E305 -1.0877E-319 +1.7729E-263 -1.5670E306
//

/* This is a automatically generated test. Do not modify */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void compute(double comp, int var_1,double var_2,double var_3,double var_4,double var_5,double var_6,double var_7,double var_8,double var_9) {
double tmp_1 = (var_2 * +0.0);
double tmp_2 = +1.4479E306;
long double comp_14_14_H = comp;
comp_14_14_H += (long double)tmp_2 - (long double)tmp_1 * (+1.2022E-312 + (long double)var_3 * (-1.9235E-81 / (+0.0 + -1.7296E305)));comp = comp_14_14_H;

comp += var_4 + (var_5 - (var_6 + (var_7 - +0.0)));
for (int i=0; i < var_1; ++i) {
  comp += (-1.7634E-312 * +1.6152E-260 + +1.1930E-51 - var_8 / var_9);
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
