/* command----------------------------------------------------------------lassen90_76688/_tests/_group_8/_test_3.c
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O0 -O0 test.c -lm
$ ./test_O0 -1.4573E-256 5 +1.5695E84 -1.2856E-312 +0.0 -1.4623E305 +1.4896E305
nan
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O3 -O3 test.c -lm
$ ./test_O3 -1.4573E-256 5 +1.5695E84 -1.2856E-312 +0.0 -1.4623E305 +1.4896E305
4.9083646616541348
--------------------------------------------------------------------------*/

/* This is a automatically generated test. Do not modify */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void compute(double comp, int var_1,double* var_2,double* var_3,double var_4,double var_5,double var_6) {
 long double comp_H = comp;
 long double var_4_H = var_4;
 long double var_5_H = var_5;
 long double var_6_H = var_6;
for (int i=0; i < var_1; ++i) {
  var_2[i] = +1.0064E-198 / var_4_H + -1.4072E-306 * +1.0390E306 / +0.0;
var_3[i] = (-1.0923E305 * +0.0);
comp_H += (long double)var_3[i] * (long double)var_2[i] - var_5_H / var_6_H - -1.9863E-317;
  printf("%d: %.17g, %.17g, %.17Lg\n", i, var_2[i], var_3[i], comp_H);
}
   printf("%.17g, %.17Lg\n", comp, comp_H);

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
  double* tmp_4 = initPointer( atof(argv[4]) );
  double tmp_5 = atof(argv[5]);
  double tmp_6 = atof(argv[6]);
  double tmp_7 = atof(argv[7]);

  compute(tmp_1,tmp_2,tmp_3,tmp_4,tmp_5,tmp_6,tmp_7);

  return 0;
}
