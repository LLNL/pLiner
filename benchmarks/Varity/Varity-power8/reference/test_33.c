/* command----------------------------------------------------------------lassen186_149959/_tests/_group_4/_test_1.c
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O0 -O0 test.c -lm
$ ./test_O0 -1.9083E-317 5 5 +1.9997E-323 -1.8556E-293 -1.9933E-282 5 +1.0919E-149 -0.0 -0.0 -1.3998E46 -1.3726E-209 +1.4581E-19 -0.0
-1.908299901254356e-317
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O3 -O3 test.c -lm
$ ./test_O3 -1.9083E-317 5 5 +1.9997E-323 -1.8556E-293 -1.9933E-282 5 +1.0919E-149 -0.0 -0.0 -1.3998E46 -1.3726E-209 +1.4581E-19 -0.0
-1.4803000000000001e-307
--------------------------------------------------------------------------*/


/* This is a automatically generated test. Do not modify */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void compute(double comp, int var_1,int var_2,double var_3,double var_4,double var_5,int var_6,double var_7,double var_8,double var_9,double var_10,double var_11,double var_12,double var_13) {
for (int i=0; i < var_1; ++i) {
  if (comp >= (+1.1317E305 / var_3 + (var_4 + (var_5 * +1.2302E-313)))) {
    for (int i=0; i < var_2; ++i) {
      double tmp_1 = atan2(+0.0, var_7 + var_8);
comp += tmp_1 - var_9 * var_10;
for (int i=0; i < var_6; ++i) {
  comp += -0.0 + var_11 * (-1.3592E-310 * -1.8350E53 / var_12);
comp = var_13 - +1.4803E-307;
}
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
  int tmp_3 = atoi(argv[3]);
  double tmp_4 = atof(argv[4]);
  double tmp_5 = atof(argv[5]);
  double tmp_6 = atof(argv[6]);
  int tmp_7 = atoi(argv[7]);
  double tmp_8 = atof(argv[8]);
  double tmp_9 = atof(argv[9]);
  double tmp_10 = atof(argv[10]);
  double tmp_11 = atof(argv[11]);
  double tmp_12 = atof(argv[12]);
  double tmp_13 = atof(argv[13]);
  double tmp_14 = atof(argv[14]);

  compute(tmp_1,tmp_2,tmp_3,tmp_4,tmp_5,tmp_6,tmp_7,tmp_8,tmp_9,tmp_10,tmp_11,tmp_12,tmp_13,tmp_14);

  return 0;
}
