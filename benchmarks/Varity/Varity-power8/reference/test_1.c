/* command----------------------------------------------------------------
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O0 -O0 _test_3.c -lm
$ ./test_O0 -1.0062E-316 5 +1.4336E-292 -1.4937E-310 -1.1557E306
-inf

$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O3 -O3 _test_3.c -lm
$ ./test_O3 -1.0062E-316 5 +1.4336E-292 -1.4937E-310 -1.1557E306
-1.0062000134493762e-316
--------------------------------------------------------------------------*/

/* This is a automatically generated test. Do not modify */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void compute(double comp, int var_1, double var_2, double var_3, double var_4) {
  for (int i = 0; i < var_1; ++i) {
    if (comp > (-1.6005E30 / var_2)) {
      comp = +1.5030E-307 / (var_3 + (-0.0 * var_4));
      double tmp_1 = +0.0;
      comp = tmp_1 + (+1.0839E78 / sin(-0.0));
    }
  }
  printf("%.17g\n", comp);
}

double *initPointer(double v) {
  double *ret = (double *)malloc(sizeof(double) * 10);
  for (int i = 0; i < 10; ++i)
    ret[i] = v;
  return ret;
}

int main(int argc, char **argv) {
  /* Program variables */

  double tmp_1 = atof(argv[1]);
  int tmp_2 = atoi(argv[2]);
  double tmp_3 = atof(argv[3]);
  double tmp_4 = atof(argv[4]);
  double tmp_5 = atof(argv[5]);

  compute(tmp_1, tmp_2, tmp_3, tmp_4, tmp_5);

  return 0;
}
