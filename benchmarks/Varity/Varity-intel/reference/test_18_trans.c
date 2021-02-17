//quartz2963_6810/_tests/_group_2/_test_4.c
//-1.7040E-315 +1.7538E-31 -1.0740E-313 +1.7869E-322 +0.0 +0.0 -0.0 5 -1.7764E306 -1.0486E-310 +1.0469E305
//

/* This is a automatically generated test. Do not modify */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void compute(double comp, double var_1,double var_2,double var_3,double var_4,double var_5,double var_6,int var_7,double var_8,double* var_9,double var_10) {
if (comp < +1.1623E305 - (var_1 / pow((var_2 / exp(+1.5102E305 * atan(+1.6137E305 - var_3 / var_4))), var_5 * +1.8179E-123 + var_6))) {
  comp = log(-1.4588E-61 + var_8);
for (int i=0; i < var_7; ++i) {
  var_9[i] = +1.1917E133;
double tmp_1 = -1.6505E-189;
double tmp_2 = -1.8981E-306;
comp = tmp_2 / tmp_1 * var_9[i] * -0.0 + var_10;
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
  int tmp_8 = atoi(argv[8]);
  double tmp_9 = atof(argv[9]);
  double* tmp_10 = initPointer( atof(argv[10]) );
  double tmp_11 = atof(argv[11]);

  compute(tmp_1,tmp_2,tmp_3,tmp_4,tmp_5,tmp_6,tmp_7,tmp_8,tmp_9,tmp_10,tmp_11);

  return 0;
}
