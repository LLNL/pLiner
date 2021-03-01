//quartz2962_37418/_tests/_group_1/_test_9.c
//+1.9855E-141 5 +1.8283E-313 +1.8972E-313 +1.7310E-307 -1.2261E-306 +1.0397E-319 -0.0 -1.1380E-307 -1.1836E-306 +0.0 -0.0 +1.2713E98
//

/* This is a automatically generated test. Do not modify */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void compute(double comp, int var_1,double var_2,double var_3,double var_4,double var_5,double var_6,double var_7,double var_8,double var_9,double var_10,double var_11,double var_12) {
double tmp_1 = +1.3775E235;
comp += tmp_1 * asin((-1.9943E182 - -1.2243E306 - (+0.0 * var_2)));
comp = -1.2746E305 - +1.2676E-306 * var_3 * cosh(log10(var_4 / -1.0505E305));
for (int i=0; i < var_1; ++i) {
  double tmp_2 = +1.6436E305;
comp = tmp_2 - -1.3152E-316 + +1.3835E24;
comp += (+1.5457E-306 / (-1.8104E306 - (+1.7668E-306 / var_5)));
comp = ((long double)var_6 + fmodl(expl((long double)var_7 / -1.2544E-306 * (long double)var_8 / (-1.2961E-317 - +1.8071E305)), (-1.2481E-317 + fabsl(((long double)var_9 - sinhl(atan2l(ceill((long double)var_10 * fabsl((-1.2694E305 * (-0.0 * (+1.5118E-312 - ((long double)var_11 / +1.4839E-307)))))), ((long double)var_12 / +1.0364E305))))))));
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
  double tmp_10 = atof(argv[10]);
  double tmp_11 = atof(argv[11]);
  double tmp_12 = atof(argv[12]);
  double tmp_13 = atof(argv[13]);

  compute(tmp_1,tmp_2,tmp_3,tmp_4,tmp_5,tmp_6,tmp_7,tmp_8,tmp_9,tmp_10,tmp_11,tmp_12,tmp_13);

  return 0;
}
