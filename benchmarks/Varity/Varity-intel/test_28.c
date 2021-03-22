//quartz2962_37433/_tests/_group_10/_test_8.c
//-1.9616E-144 -1.8700E-323 -1.7337E306 -1.0613E-306 5 -1.0053E-2 +1.6696E306 -1.7560E305 -1.3869E-307 -0.0 +1.4481E306 +1.0961E273 +1.5493E-307 -0.0 +1.1656E-306 +1.7720E305 -1.8147E-316
//

/* This is a automatically generated test. Do not modify */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void compute(double comp, double var_1,double var_2,double var_3,int var_4,double var_5,double var_6,double var_7,double var_8,double var_9,double var_10,double var_11,double var_12,double var_13,double var_14,double var_15,double var_16) {
if (comp <= sqrt(var_1 - (var_2 / var_3 * +0.0))) {
  comp += (var_5 * var_6 / (+1.8331E282 / -1.5538E-258 + (-1.6295E-317 * -1.0037E-307)));
comp += (+1.3273E-318 + -1.8886E-311 * +1.0109E-316 * +1.6171E-307);
comp += -1.3457E31 / tanh((-0.0 + +1.3744E-306));
if (comp < (-0.0 + -1.6701E-306)) {
  comp = sqrt(fmod((var_7 * tanh((-1.0760E-307 * +0.0))), (var_8 * tanh((+1.4150E306 / var_9)))));
double tmp_1 = -0.0;
comp += tmp_1 - var_10 / var_11 + var_12 * tanh(var_13 * (-1.3442E-306 / +1.7887E-307));
}
for (int i=0; i < var_4; ++i) {
  double tmp_2 = -1.6517E281;
comp += tmp_2 - (var_14 / -1.4732E172 * (+0.0 / var_15 * var_16));
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
  int tmp_5 = atoi(argv[5]);
  double tmp_6 = atof(argv[6]);
  double tmp_7 = atof(argv[7]);
  double tmp_8 = atof(argv[8]);
  double tmp_9 = atof(argv[9]);
  double tmp_10 = atof(argv[10]);
  double tmp_11 = atof(argv[11]);
  double tmp_12 = atof(argv[12]);
  double tmp_13 = atof(argv[13]);
  double tmp_14 = atof(argv[14]);
  double tmp_15 = atof(argv[15]);
  double tmp_16 = atof(argv[16]);
  double tmp_17 = atof(argv[17]);

  compute(tmp_1,tmp_2,tmp_3,tmp_4,tmp_5,tmp_6,tmp_7,tmp_8,tmp_9,tmp_10,tmp_11,tmp_12,tmp_13,tmp_14,tmp_15,tmp_16,tmp_17);

  return 0;
}
