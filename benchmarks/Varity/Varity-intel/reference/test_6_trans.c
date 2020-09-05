//quartz2962_37433/_tests/_group_10/_test_4.c
//-1.2118E171 -1.5450E305 -1.1051E280 -0.0 +1.9585E-322 -0.0 -1.5091E-307
//

/* This is a automatically generated test. Do not modify */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void compute(double comp, double var_1,double var_2,double var_3,double var_4,double var_5,double var_6) {
comp = +1.5518E305 - ((long double)var_1 - (long double)var_2 * +1.7864E-227);
double tmp_1 = var_3 * (var_4 + var_5 - var_6);
comp += tmp_1 / +1.8082E306 * +1.7318E-312 - -1.1887E306;
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

  compute(tmp_1,tmp_2,tmp_3,tmp_4,tmp_5,tmp_6,tmp_7);

  return 0;
}
