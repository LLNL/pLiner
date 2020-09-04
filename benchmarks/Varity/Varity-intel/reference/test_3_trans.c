//quartz2963_6790/_tests/_group_4/_test_8.c
//+1.0587E-88 +1.0282E306 -1.0115E-322
//

/* This is a automatically generated test. Do not modify */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void compute(double comp, double var_1,double var_2) {
long double comp_12_12_H = comp;
comp_12_12_H += ((long double)var_1 * (long double)var_2);comp = comp_12_12_H;

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

  compute(tmp_1,tmp_2,tmp_3);

  return 0;
}
