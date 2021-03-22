/* command----------------------------------------------------------------lassen555_152297/_tests/_group_6/_test_4.c
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O0 -O0 test.c -lm
$ ./test_O0 -0.0 5 -1.4445E-320 -1.6405E-320 -1.5621E306
7.1042170694197034e-307
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O3 -O3 test.c -lm
$ ./test_O3 -0.0 5 -1.4445E-320 -1.6405E-320 -1.5621E306
7.1042170694437451e-307
--------------------------------------------------------------------------*/


/* This is a automatically generated test. Do not modify */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void compute(double comp, int var_1,double var_2,double var_3,double var_4) {
for (int i=0; i < var_1; ++i) {
  long double comp_19_19_H = comp;
  comp_19_19_H += (+1.4303E-307 + ((long double)var_2 + (long double)var_3 / ((long double)var_4 * -1.1104E-317)));comp = comp_19_19_H;
  
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

  compute(tmp_1,tmp_2,tmp_3,tmp_4,tmp_5);

  return 0;
}
