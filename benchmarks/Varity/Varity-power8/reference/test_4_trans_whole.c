/* command----------------------------------------------------------------lassen439_81565_tests_group_3_test_5.c
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O0 -O0 test.c -lm
$ ./test_O0 +0.0 5 -1.0184E-311 +1.7067E277 -1.6847E-306 +1.8873E-321 -1.7196E132 -1.9874E-320 +1.0539E-307 -1.2192E-306 +0.0 +1.0069E305 -1.3774E-306 -1.2990E-317 +0.0 +1.6335E-307 -1.6584E-162
nan
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O3 -O3 test.c -lm
$ ./test_O3 +0.0 5 -1.0184E-311 +1.7067E277 -1.6847E-306 +1.8873E-321 -1.7196E132 -1.9874E-320 +1.0539E-307 -1.2192E-306 +0.0 +1.0069E305 -1.3774E-306 -1.2990E-317 +0.0 +1.6335E-307 -1.6584E-162
1.3407639380493153
--------------------------------------------------------------------------*/


/* This is a automatically generated test. Do not modify */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void compute(double comp, int var_1,double var_2,double var_3,double var_4,double var_5,double var_6,double var_7,double var_8,double var_9,double var_10,double var_11,double var_12,double var_13,double var_14,double var_15,double var_16) {
 long double comp_H = comp;
 long double var_2_H = var_2;
 long double var_3_H = var_3;
 long double var_4_H = var_4;
 long double var_5_H = var_5;
 long double var_6_H = var_6;
 long double var_7_H = var_7;
 long double var_8_H = var_8;
 long double var_9_H = var_9;
 long double var_10_H = var_10;
 long double var_11_H = var_11;
 long double var_12_H = var_12;
 long double var_13_H = var_13;
 long double var_14_H = var_14;
 long double var_15_H = var_15;
 long double var_16_H = var_16;
for (int i=0; i < var_1; ++i) {
  comp_H += (var_2_H / +1.6922E305 - (var_3_H - var_4_H));
comp_H += cosl(-1.4280E-322 + acosl(var_5_H + -1.3779E211 + -1.4439E-179));
comp_H += +0.0 + (var_6_H - var_7_H);
long double tmp =  var_8_H + (var_9_H - var_10_H);
printf ("%.17Lg, %.17Lg\n", comp_H, tmp);
if (comp_H <= tmp) {
//if (comp_H <= var_8_H + (var_9_H - var_10_H)) {
  printf("entering the true-branch\n");
  comp_H = -1.2323E-159 + +1.1231E117 * var_11_H;
comp_H = var_12_H / fmodl(-1.7222E223 - (var_13_H - -1.0890E-307), +1.3373E-306);
comp_H += (var_14_H + sinhl(var_15_H + -0.0 * var_16_H));
}
}
   printf("%.17Lg\n", comp_H);

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
