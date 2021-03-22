//quartz2962_37417/_tests/_group_4/_test_6.c
//+1.5018E-306 5 -1.0406E153 -1.2710E-37 -0.0 +1.3078E-306 -0.0 -1.7365E-310 +1.0123E305 +0.0 +0.0 +1.6932E-306 +1.2418E-307 +1.2903E-317 +1.6288E-314 +0.0 +0.0
//

/* This is a automatically generated test. Do not modify */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void compute(double comp, int var_1,double var_2,double var_3,double var_4,double var_5,double var_6,double var_7,double var_8,double* var_9,double var_10,double var_11,double var_12,double var_13,double var_14,double var_15,double var_16) {
comp = (-1.7716E-307 * +1.2561E306 / -0.0);
double tmp_1 = (var_2 - var_3 - (var_4 + log10((var_5 * floor(var_6 - var_7 * var_8 + sqrt((-0.0 + +0.0 + (+1.6521E-46 * -1.1415E305))))))));
comp += tmp_1 + fmod(+1.4922E306, +1.9929E-267);
for (int i=0; i < var_1; ++i) {
  comp += var_10 - var_11;
var_9[i] = sin(-1.1311E-311 + -1.2324E-54 + -1.8156E-307);
comp = var_9[i] * atan2((var_12 * (+0.0 + log(var_13 + var_14))), -1.9226E306);
comp += (var_15 + var_16);
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
  double* tmp_10 = initPointer( atof(argv[10]) );
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
