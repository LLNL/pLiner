/* command----------------------------------------------------------------lassen321_161433/_tests/_group_6/_test_1.c
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O0 -O0 test.c -lm
$ ./test_O0 -1.2882E-321 -0.0 -1.0422E306 -1.0484E-320 -1.8580E-292 +1.4516E306 +1.3656E-65 +0.0 5 +1.7659E-306 -1.2991E-307 +0.0 -1.9299E-321 +1.9395E305 +1.2766E-238 +1.5682E305 +0.0 +1.5034E-166 +1.8783E-207 +1.0022E-307 -0.0
-1.2895113356456535e-321
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O3 -O3 test.c -lm
$ ./test_O3 -1.2882E-321 -0.0 -1.0422E306 -1.0484E-320 -1.8580E-292 +1.4516E306 +1.3656E-65 +0.0 5 +1.7659E-306 -1.2991E-307 +0.0 -1.9299E-321 +1.9395E305 +1.2766E-238 +1.5682E305 +0.0 +1.5034E-166 +1.8783E-207 +1.0022E-307 -0.0
-inf
--------------------------------------------------------------------------*/


/* This is a automatically generated test. Do not modify */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void compute(double comp, double var_1,double var_2,double var_3,double var_4,double var_5,double var_6,double var_7,int var_8,double var_9,double var_10,double var_11,double var_12,double var_13,double var_14,double var_15,double var_16,double var_17,double var_18,double var_19,double var_20) {
 long double comp_H = comp;
 long double var_1_H = var_1;
 long double var_2_H = var_2;
 long double var_3_H = var_3;
 long double var_4_H = var_4;
 long double var_5_H = var_5;
 long double var_6_H = var_6;
 long double var_7_H = var_7;
 long double var_9_H = var_9;
 long double var_10_H = var_10;
 long double var_11_H = var_11;
 long double var_12_H = var_12;
 long double var_13_H = var_13;
 long double var_14_H = var_14;
 long double var_15_H = var_15;
 long double var_16_H = var_16;
 long double var_17_H = var_17;
 long double var_18_H = var_18;
 long double var_19_H = var_19;
 long double var_20_H = var_20;
 long double tmp = var_1_H - powl((var_2_H + powl(+1.7187E-313 - cosl((var_3_H + -1.7924E-322)), +0.0 / (var_4_H + var_5_H - -1.8962E238))), var_6_H - var_7_H);
 if (comp_H >= tmp) { 
//if (comp_H >= var_1_H - powl((var_2_H + powl(+1.7187E-313 - cosl((var_3_H + -1.7924E-322)), +0.0 / (var_4_H + var_5_H - -1.8962E238))), var_6_H - var_7_H)) {
  printf("entering true-branch\n");
  comp_H = powl(-1.0468E306 - +1.1925E-310 - var_9_H, var_10_H / -1.8819E-307 + (+0.0 * (+1.6664E-315 / var_11_H)));
for (int i=0; i < var_8; ++i) {
  comp_H += +1.9379E-306 / (var_12_H * -1.9309E-77);
comp_H = log10l((-0.0 * var_13_H));
comp_H += +0.0 * (+0.0 - (var_14_H + var_15_H));
}
if (comp_H > (var_16_H * var_17_H * +1.9376E306 + var_18_H)) {
  comp_H = +0.0 / +1.6262E-314 / ldexpl(var_19_H * powl(+1.0431E-44, (var_20_H / atanl(+1.0734E306))), 2);
}
}
   printf("%.17g, %.17Lg, %.17Lg\n", comp, tmp, comp_H);

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
  double tmp_8 = atof(argv[8]);
  int tmp_9 = atoi(argv[9]);
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

  compute(tmp_1,tmp_2,tmp_3,tmp_4,tmp_5,tmp_6,tmp_7,tmp_8,tmp_9,tmp_10,tmp_11,tmp_12,tmp_13,tmp_14,tmp_15,tmp_16,tmp_17,tmp_18,tmp_19,tmp_20,tmp_21);

  return 0;
}
