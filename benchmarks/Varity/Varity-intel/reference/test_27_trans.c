//quartz2962_37427/_tests/_group_10/_test_2.c
//+1.5370E-306 5 -1.5803E-44 -0.0 -1.6062E174
//

/* This is a automatically generated test. Do not modify */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void compute(double comp, int var_1,double var_2,double var_3,double var_4) {
long double comp_12_15_H = comp;
for (int i=0; i < var_1; ++i) {
  long double tmp_1_12_15_H = +0.0;
comp_12_15_H += tmp_1_12_15_H - +0.0 - (long double)var_2 / (-1.6278E-307 / (+1.1623E-289 + (long double)var_3 * (long double)var_4));comp = comp_12_15_H;

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

  compute(tmp_1,tmp_2,tmp_3,tmp_4,tmp_5);

  return 0;
}
