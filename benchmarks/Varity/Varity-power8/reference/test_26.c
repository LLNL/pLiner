/* command----------------------------------------------------------------lassen459_75134/_tests/_group_8/_test_1.c
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O0 -O0 test.c -lm
$ ./test_O0 +1.4413E-307 5 -0.0 5 -0.0 +1.5834E26 -1.7405E230 +1.1456E-306 +1.9167E-310 +1.3826E210 -1.7196E-307 -1.4485E-312 +1.1165E-307 +1.6553E305 +0.0
inf
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O3 -O3 test.c -lm
$ ./test_O3 +1.4413E-307 5 -0.0 5 -0.0 +1.5834E26 -1.7405E230 +1.1456E-306 +1.9167E-310 +1.3826E210 -1.7196E-307 -1.4485E-312 +1.1165E-307 +1.6553E305 +0.0
nan
--------------------------------------------------------------------------*/


/* This is a automatically generated test. Do not modify */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void compute(double comp, int var_1,double* var_2,int var_3,double var_4,double var_5,double var_6,double var_7,double var_8,double var_9,double var_10,double var_11,double var_12,double var_13,double var_14) {
for (int i=0; i < var_1; ++i) {
  var_2[i] = +1.5340E-314;
comp = var_2[i] / -1.0366E306 / (-0.0 + (var_4 * pow(floor(-1.3625E305 / var_5 - +1.1426E-307 * sin(+0.0)), +1.2539E-307 / (var_6 / +1.9888E-142 + var_7 + var_8))));
comp = var_9 / ldexp((var_10 - asin((-1.9791E68 * var_11))), 2);
for (int i=0; i < var_3; ++i) {
  comp = var_12 / +0.0;
double tmp_1 = ldexp(+0.0, 2);
comp += tmp_1 + cos(var_13 - var_14 + +1.3058E-22);
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
  double* tmp_3 = initPointer( atof(argv[3]) );
  int tmp_4 = atoi(argv[4]);
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

  compute(tmp_1,tmp_2,tmp_3,tmp_4,tmp_5,tmp_6,tmp_7,tmp_8,tmp_9,tmp_10,tmp_11,tmp_12,tmp_13,tmp_14,tmp_15);

  return 0;
}
