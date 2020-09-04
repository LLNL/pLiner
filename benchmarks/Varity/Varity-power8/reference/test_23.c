/* command----------------------------------------------------------------lassen230_2719/_tests/_group_3/_test_4.c
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O0 -O0 test.c -lm
$ ./test_O0 -0.0 +1.7082E-190 -1.8654E-306 -1.8930E-310 +1.8408E-212 -1.6621E-318
6.9740229347062958e+54
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O3 -O3 test.c -lm
$ ./test_O3 -0.0 +1.7082E-190 -1.8654E-306 -1.8930E-310 +1.8408E-212 -1.6621E-318
nan
--------------------------------------------------------------------------*/


/* This is a automatically generated test. Do not modify */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void compute(double comp, double var_1,double var_2,double var_3,double var_4,double var_5) {
comp += +1.9935E-76 * var_1 - (+1.3623E-306 + acos(-1.7511E-318));
double tmp_1 = (+1.3708E-251 / (+1.0018E-307 - var_2));
comp = tmp_1 - (var_3 * var_4 / var_5);
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

  compute(tmp_1,tmp_2,tmp_3,tmp_4,tmp_5,tmp_6);

  return 0;
}
