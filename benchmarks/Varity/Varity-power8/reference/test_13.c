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
if (comp <= log10(var_2 / var_3 - var_4)) {
  for (int i=0; i < var_1; ++i) {
    if (comp < ceil(var_5 + +1.2929E-117)) {
      comp = (var_6 + (+1.2005E306 * var_7 - (var_8 + var_9)));
comp += var_10 * (+1.5710E-314 / var_11 / (var_12 - -1.6927E306));
}
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
  double tmp_9 = atof(argv[9]);
  double tmp_10 = atof(argv[10]);
  double tmp_11 = atof(argv[11]);
  double tmp_12 = atof(argv[12]);
  double tmp_13 = atof(argv[13]);

  compute(tmp_1,tmp_2,tmp_3,tmp_4,tmp_5,tmp_6,tmp_7,tmp_8,tmp_9,tmp_10,tmp_11,tmp_12,tmp_13);

  return 0;
}
