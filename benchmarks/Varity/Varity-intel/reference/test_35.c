//quartz2963_6813/_tests/_group_10/_test_2.c
//+1.8489E-310 +1.5807E-289 -1.0316E306 +1.4235E-322 +1.5064E-306
//

/* This is a automatically generated test. Do not modify */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void compute(double comp, double var_1,double var_2,double var_3,double var_4) {
comp = (var_1 / var_2);
double tmp_1 = +1.8113E-318;
comp += tmp_1 + (-1.0898E-307 / exp(+1.2952E-37));
comp += var_3 / log(+1.0770E305 * var_4);
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
