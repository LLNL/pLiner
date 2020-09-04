/* command----------------------------------------------------------------lassen610_37306/_tests/_group_6/_test_4.c
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O0 -O0 test.c -lm
$ ./test_O0 +1.2459E-315 5 +0.0 -1.4250E-306 +1.9721E305 -0.0 -1.4454E-207 +1.2542E-267 -1.4631E-306 -1.8994E-75 -1.0306E-306 -1.6409E-307 +1.1696E-310
1.2458999980455835e-315
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O3 -O3 test.c -lm
$ ./test_O3 +1.2459E-315 5 +0.0 -1.4250E-306 +1.9721E305 -0.0 -1.4454E-207 +1.2542E-267 -1.4631E-306 -1.8994E-75 -1.0306E-306 -1.6409E-307 +1.1696E-310
1.5056671e+39
--------------------------------------------------------------------------*/


/* This is a automatically generated test. Do not modify */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void compute(double comp, int var_1,double var_2,double var_3,double var_4,double var_5,double var_6,double var_7,double var_8,double var_9,double var_10,double var_11,double var_12) {
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
if (comp_H <= log10l(var_2_H / var_3_H - var_4_H)) {
  for (int i=0; i < var_1; ++i) {
    if (comp_H < ceill(var_5_H + +1.2929E-117)) {
      comp_H = (var_6_H + (+1.2005E306 * var_7_H - (var_8_H + var_9_H)));
comp_H += var_10_H * (+1.5710E-314 / var_11_H / (var_12_H - -1.6927E306));
}
}
}
   printf("%.17g\n", comp_H);

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
