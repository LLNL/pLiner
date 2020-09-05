//quartz2963_6797/_tests/_group_9/_test_6.c
//-1.7429E306 5 +1.1507E-307 +1.6127E-306 -0.0 -1.8892E305 -1.1840E-174 -1.5390E-323 -1.3612E-314 -1.7270E-306 +0.0 -1.1017E306 +1.4633E-306 -0.0 +1.5141E305 +1.1080E-306 +1.7194E-306 -1.4045E306 +1.8136E-306 -1.2662E-306 -0.0 +1.9301E-173
//

/* This is a automatically generated test. Do not modify */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void compute(double comp, int var_1,double var_2,double var_3,double var_4,double* var_5,double var_6,double var_7,double var_8,double var_9,double var_10,double var_11,double var_12,double var_13,double var_14,double var_15,double var_16,double var_17,double var_18,double var_19,double var_20,double var_21) {
comp += var_2 + (-1.3775E-69 * floor((var_3 - (+1.0406E-306 / -1.7924E-314 - (+0.0 + var_4)))));
for (int i=0; i < var_1; ++i) {
  var_5[i] = (var_6 - var_7 * (var_8 * var_9 - var_10));
comp += var_5[i] * exp((var_11 + asin((var_12 - var_13 + (var_14 - var_15 * var_16)))));
comp += var_17 - (-0.0 - -1.7056E305);
comp = (var_18 / var_19);
}
if (comp > (-1.3857E-321 / (-1.9188E306 * var_20))) {
  comp += -1.6039E305 - (-1.1362E99 * var_21);
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
  double* tmp_6 = initPointer( atof(argv[6]) );
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
  double tmp_18 = atof(argv[18]);
  double tmp_19 = atof(argv[19]);
  double tmp_20 = atof(argv[20]);
  double tmp_21 = atof(argv[21]);
  double tmp_22 = atof(argv[22]);

  compute(tmp_1,tmp_2,tmp_3,tmp_4,tmp_5,tmp_6,tmp_7,tmp_8,tmp_9,tmp_10,tmp_11,tmp_12,tmp_13,tmp_14,tmp_15,tmp_16,tmp_17,tmp_18,tmp_19,tmp_20,tmp_21,tmp_22);

  return 0;
}
