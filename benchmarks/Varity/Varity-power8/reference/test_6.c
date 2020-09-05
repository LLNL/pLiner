/* command----------------------------------------------------------------lassen555_152296/_tests/_group_7/_test_8.c
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O0 -O0 test.c -lm
$ ./test_O0 -1.3020E-321 +1.8570E-307 +1.7614E305 -1.1716E-314 +1.0844E-242
nan
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O3 -O3 test.c -lm
$ ./test_O3 -1.3020E-321 +1.8570E-307 +1.7614E305 -1.1716E-314 +1.0844E-242
1
--------------------------------------------------------------------------*/

/* This is a automatically generated test. Do not modify */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void compute(double comp, double var_1,double var_2,double var_3,double var_4) {
comp += exp((var_1 * (+1.3267E-306 * -1.2744E-319 / cos(-1.2517E279 * fmod((-0.0 + floor(+0.0)), exp(var_2 / var_3))))));
comp += +1.5867E-306 / (var_4 + -0.0);
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
