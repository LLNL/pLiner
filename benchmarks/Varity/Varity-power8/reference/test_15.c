/* command----------------------------------------------------------------lassen387_54605/_tests/_group_5/_test_5.c
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O0 -O0 test.c -lm
$ ./test_O0 -0.0 5 +1.4983E-307 +1.0563E306
-inf
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O3 -O3 test.c -lm
$ ./test_O3 -0.0 5 +1.4983E-307 +1.0563E306
nan
--------------------------------------------------------------------------*/


/* This is a automatically generated test. Do not modify */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void compute(double comp, int var_1,double var_2,double var_3) {
for (int i=0; i < var_1; ++i) {
  comp = (var_2 / -0.0 - floor(+1.7063E232));
comp += ceil(+1.3476E175 - var_3);
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

  compute(tmp_1,tmp_2,tmp_3,tmp_4);

  return 0;
}
