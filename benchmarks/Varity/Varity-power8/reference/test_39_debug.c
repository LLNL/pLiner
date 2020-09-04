/* command----------------------------------------------------------------lassen320_3047_tests_group_6_test_7.c
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O0 -O0 test.c -lm
$ ./test_O0 +1.5590E-306 +0.0 +0.0 -1.4801E305 +1.8670E-307 -1.4230E-307 +0.0 +1.9887E-320 +1.8139E-306 +1.1686E306 +1.7314E305
1.3723000001654872e-306
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O3 -O3 test.c -lm
$ ./test_O3 +1.5590E-306 +0.0 +0.0 -1.4801E305 +1.8670E-307 -1.4230E-307 +0.0 +1.9887E-320 +1.8139E-306 +1.1686E306 +1.7314E305
1.5590000000000001e-306
--------------------------------------------------------------------------*/

/* This is a automatically generated test. Do not modify */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void compute(double comp, double var_1,double var_2,double var_3,double var_4,double var_5,double var_6,double var_7,double var_8,double var_9,double var_10) {
double mytmp = var_3 / -1.8131E-319;
printf("%.17g\n", mytmp);

double tmp1 = atan2(var_3 / -1.8131E-319, -1.0247E305);
printf("%.17g = atan2(%.17g / -1.8131E-319, -1.0247E305))\n", tmp1, var_3);

double tmp2 = var_1 / +1.4859E-310 + (var_2 * atan2(var_3 / -1.8131E-319, -1.0247E305));
printf("%.17g = %.17g / +1.4859E-310 + (%.17g * atan2(%.17g / -1.8131E-319, -1.0247E305))\n", tmp2, var_1, var_2, var_3);
if (comp > (var_1 / +1.4859E-310 + (var_2 * atan2(var_3 / -1.8131E-319, -1.0247E305)))) {
  printf("%.17g > %.17g \n", comp, tmp2);
  comp += (var_4 * (var_5 - pow(var_6 * +0.0 / sin((var_7 * +1.5574E204 - sinh(+0.0))), fabs(+0.0))));
comp += atan((+1.9531E-310 * (+1.3782E-312 / (-1.8733E-307 + sinh(var_8 + ldexp(+1.6580E-318, 2))))));
if (comp >= ldexp(+1.5912E200, 2)) {
  comp += var_9 - -0.0 * (var_10 / -1.3628E154);
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
  double tmp_2 = atof(argv[2]);
  double tmp_3 = atof(argv[3]);
  double tmp_4 = atof(argv[4]);
  double tmp_5 = atof(argv[5]);
  double tmp_6 = atof(argv[6]);
  double tmp_7 = atof(argv[7]);
  double tmp_8 = atof(argv[8]);
  double tmp_9 = atof(argv[9]);
  double tmp_10 = atof(argv[10]);
  double tmp_11 = atof(argv[11]);

  compute(tmp_1,tmp_2,tmp_3,tmp_4,tmp_5,tmp_6,tmp_7,tmp_8,tmp_9,tmp_10,tmp_11);

  return 0;
}
