//quartz2962_37415/_tests/_group_2/_test_4.c
//-1.3643E-319 5 -1.2777E5 +0.0 +1.8287E305 +1.1602E306 -1.3764E-123 +0.0
//

/* This is a automatically generated test. Do not modify */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void compute(double comp, int var_1,double var_2,double var_3,double var_4,double var_5,double var_6,double var_7) {
if (comp >= -1.8978E-307 / -1.2428E-306 * -1.8803E-319) {
  double tmp_1 = -1.9956E-29;
comp = tmp_1 - var_2 + (var_3 * exp(-1.7189E-306 * (-1.6418E-314 - var_4 * var_5)));
comp = cos(sqrt(-0.0 - (+0.0 + var_6)));
for (int i=0; i < var_1; ++i) {
  comp += +1.7108E-306 - var_7;
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

  compute(tmp_1,tmp_2,tmp_3,tmp_4,tmp_5,tmp_6,tmp_7,tmp_8);

  return 0;
}
