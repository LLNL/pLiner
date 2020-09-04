/* command----------------------------------------------------------------lassen800_140197/_tests/_group_9/_test_9.c
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O0 -O0 test.c -lm
$ ./test_O0 +1.1202E-109 5 5 -0.0 -1.6442E305 +1.2116E-318 +1.4163E-323 -1.4990E-307 +1.3586E233 +0.0 -1.3025E-306 -1.3827E-307 -1.2198E-306 +1.5508E-314 -1.8305E305 -1.3803E-120 -1.5401E-322 +1.8788E-316 +1.7199E-306
1052069181630308.4
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O3 -O3 test.c -lm
$ ./test_O3 +1.1202E-109 5 5 -0.0 -1.6442E305 +1.2116E-318 +1.4163E-323 -1.4990E-307 +1.3586E233 +0.0 -1.3025E-306 -1.3827E-307 -1.2198E-306 +1.5508E-314 -1.8305E305 -1.3803E-120 -1.5401E-322 +1.8788E-316 +1.7199E-306
nan
--------------------------------------------------------------------------*/


/* This is a automatically generated test. Do not modify */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void compute(double comp, int var_1,int var_2,double var_3,double var_4,double var_5,double var_6,double var_7,double* var_8,double var_9,double var_10,double var_11,double var_12,double* var_13,double* var_14,double var_15,double var_16,double var_17,double var_18) {
double tmp_1 = -1.2428E-320;
comp = tmp_1 / (+1.8327E-318 - sin(cos((var_3 + (-1.2619E15 + var_4)))));
comp = var_5 * tanh((var_6 - (-1.0360E167 + var_7)));
for (int i=0; i < var_1; ++i) {
  var_8[i] = -0.0 / (var_9 * +1.9036E-317 + var_10 - +1.3400E-306);
comp = var_8[i] + var_11 - -0.0;
comp += var_12 * (+1.7482E-307 + +1.1241E-311);
}
for (int i=0; i < var_2; ++i) {
  printf("var_15=%.17g, var_16=%.17g\n", var_15, var_16);
  var_13[i] = sin(var_15 / +1.7793E-307);
  var_14[i] = (+1.3131E-307 / var_16);
  printf("var_13[%d]=%.17g, var_14[%d]=%.17g\n", i, var_13[i], i, var_14[i]);
  comp = var_14[i] / var_13[i] - sqrt((var_17 + tanh(-0.0 / (+1.8254E-121 - (var_18 * -0.0)))));
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
  double* tmp_9 = initPointer( atof(argv[9]) );
  double tmp_10 = atof(argv[10]);
  double tmp_11 = atof(argv[11]);
  double tmp_12 = atof(argv[12]);
  double tmp_13 = atof(argv[13]);
  double* tmp_14 = initPointer( atof(argv[14]) );
  double* tmp_15 = initPointer( atof(argv[15]) );
  double tmp_16 = atof(argv[16]);
  double tmp_17 = atof(argv[17]);
  double tmp_18 = atof(argv[18]);
  double tmp_19 = atof(argv[19]);

  compute(tmp_1,tmp_2,tmp_3,tmp_4,tmp_5,tmp_6,tmp_7,tmp_8,tmp_9,tmp_10,tmp_11,tmp_12,tmp_13,tmp_14,tmp_15,tmp_16,tmp_17,tmp_18,tmp_19);

  return 0;
}
