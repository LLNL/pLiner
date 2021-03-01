//quartz2962_37437/_tests/_group_6/_test_5.c
//-1.0361E-306 5 5 +1.5394E-306 +0.0 +1.6569E-158 +1.9958E-307 -1.6859E-307 -1.6693E305 -0.0 -1.2347E305 -1.3951E-314 +1.1210E306 +0.0 +1.8751E-307 -1.4518E-310 +1.9156E305 -1.3713E14 -1.7271E305 +1.6661E306 -0.0 +1.4086E-214 +1.8005E305
//

/* This is a automatically generated test. Do not modify */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void compute(double comp, int var_1,int var_2,double var_3,double var_4,double var_5,double var_6,double var_7,double var_8,double var_9,double var_10,double* var_11,double* var_12,double var_13,double var_14,double var_15,double var_16,double var_17,double var_18,double var_19,double var_20,double var_21,double var_22) {
for (int i=0; i < var_1; ++i) {
  double tmp_1 = var_3 - asin(+0.0);
comp += tmp_1 * var_4 / var_5;
comp = var_6 / var_7;
comp += -1.9141E306 + (var_8 + (var_9 / +1.5965E305 - var_10 + -0.0));
for (int i=0; i < var_2; ++i) {
  var_11[i] = var_13 + var_14 + +1.3391E-316 + (+1.6362E-320 * -1.9803E305 - +1.5224E-313);
var_12[i] = +0.0;
comp += var_12[i] + var_11[i] + (var_15 + (var_16 - var_17));
}
double tmp1 = +0.0 / pow(ceil((var_18 + var_19 * var_20)), asin(+1.3201E-306));
printf("%.17g, %.17g\n", comp, tmp1);
if (comp < (+0.0 / pow(ceil((var_18 + var_19 * var_20)), asin(+1.3201E-306)))) {
  printf("%.17g < %.17g\n", comp, tmp1);
  double tmp_2 = +1.1175E-313;
comp = tmp_2 * var_21 + +1.7975E-285 * -1.0196E-307 - var_22;
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
  int tmp_3 = atoi(argv[3]);
  double tmp_4 = atof(argv[4]);
  double tmp_5 = atof(argv[5]);
  double tmp_6 = atof(argv[6]);
  double tmp_7 = atof(argv[7]);
  double tmp_8 = atof(argv[8]);
  double tmp_9 = atof(argv[9]);
  double tmp_10 = atof(argv[10]);
  double tmp_11 = atof(argv[11]);
  double* tmp_12 = initPointer( atof(argv[12]) );
  double* tmp_13 = initPointer( atof(argv[13]) );
  double tmp_14 = atof(argv[14]);
  double tmp_15 = atof(argv[15]);
  double tmp_16 = atof(argv[16]);
  double tmp_17 = atof(argv[17]);
  double tmp_18 = atof(argv[18]);
  double tmp_19 = atof(argv[19]);
  double tmp_20 = atof(argv[20]);
  double tmp_21 = atof(argv[21]);
  double tmp_22 = atof(argv[22]);
  double tmp_23 = atof(argv[23]);

  compute(tmp_1,tmp_2,tmp_3,tmp_4,tmp_5,tmp_6,tmp_7,tmp_8,tmp_9,tmp_10,tmp_11,tmp_12,tmp_13,tmp_14,tmp_15,tmp_16,tmp_17,tmp_18,tmp_19,tmp_20,tmp_21,tmp_22,tmp_23);

  return 0;
}
