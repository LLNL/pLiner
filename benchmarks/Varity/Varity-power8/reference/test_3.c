/* command-------------------------------------------------------------------------------------------------------------------------------------
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O0 -O0 _test_3.c -lm
$ ./test_O0 +1.9797E-307 5 -1.6381E-322 +1.6636E-231 -1.3601E-315 -1.9729E-264 +1.2209E-306 -0.0 +1.1903E-276 -0.0 -1.6286E305 +0.0 +1.9088E-307
5.2459999999999996e+305

$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O3 -O3 _test_3.c -lm
$ ./test_O3 +1.9797E-307 5 -1.6381E-322 +1.6636E-231 -1.3601E-315 -1.9729E-264 +1.2209E-306 -0.0 +1.1903E-276 -0.0 -1.6286E305 +0.0 +1.9088E-307
inf
------------------------------------------------------------------------------------------------------------------------------------------------*/

/* This is a automatically generated test. Do not modify */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void compute(double comp, int var_1, double var_2, double var_3, double var_4,
             double var_5, double var_6, double var_7, double var_8,
             double var_9, double var_10, double var_11, double var_12) {
  for (int i = 0; i < var_1; ++i) {
    comp += +1.0492E305 + var_2 / -1.3627E-314;
    if (comp <= (var_3 / +1.6496E-307)) {
      comp = +1.4364E-314 * +1.1893E118;
      double tmp_1 =
          (-1.5996E-306 - fmod(-0.0 * -1.6276E-306 *
                                   (var_4 * atan((+1.4017E-311 + +1.2988E-130 +
                                                  (+1.9335E-320 + var_5)))),
                               +1.3936E13 + (var_6 + (var_7 + -1.1549E305))));
      comp = tmp_1 + (var_8 * (-0.0 / var_9));
    }
    if (comp > var_10 - (var_11 + var_12)) {
      double tmp_2 = +1.5206E-307;
      comp += tmp_2 - tanh(+0.0);
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
  double tmp_6 = atof(argv[6]);
  double tmp_7 = atof(argv[7]);
  double tmp_8 = atof(argv[8]);
  double tmp_9 = atof(argv[9]);
  double tmp_10 = atof(argv[10]);
  double tmp_11 = atof(argv[11]);
  double tmp_12 = atof(argv[12]);
  double tmp_13 = atof(argv[13]);

  compute(tmp_1, tmp_2, tmp_3, tmp_4, tmp_5, tmp_6, tmp_7, tmp_8, tmp_9, tmp_10,
          tmp_11, tmp_12, tmp_13);

  return 0;
}
