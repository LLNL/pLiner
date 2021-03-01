/* command----------------------------------------------------------------lassen61_176706/_tests/_group_10/_test_1.c
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O0 -O0 test.c -lm
$ ./test_O0 +0.0 +0.0 +1.4367E-322 -1.9527E138 -1.5668E306
0
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O3 -O3 test.c -lm
$ ./test_O3 +0.0 +0.0 +1.4367E-322 -1.9527E138 -1.5668E306
nan
--------------------------------------------------------------------------*/


/* This is a automatically generated test. Do not modify */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void compute(double comp, double var_1,double var_2,double var_3,double var_4) {
long double comp_18_19_H = comp;
comp_18_19_H += (-1.7054E-306 * +1.5743E125 / (-1.1391E195 + sqrt(((long double)var_1 / ((long double)var_2 - sin(((long double)var_3 + (-1.3232E305 / ((long double)var_4 - (+0.0 + -0.0))))))))));
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

  compute(tmp_1,tmp_2,tmp_3,tmp_4,tmp_5);

  return 0;
}
