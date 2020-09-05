/* command-------------------------------------------------------------------------------------------------------------------------------------------------------------
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O0 -O0 _test_1.c -lm
$./test_O0 -1.7318E-306 +0.0 +1.3481E-317 +0.0 +0.0 +1.2605E232 +0.0 -1.3125E-306 +1.0497E-316 -0.0 +1.6345E-306 -1.4350E306 -1.1637E306 -0.0 -1.4425E-306 -1.0964E279
-1.7317999999999999e-306

$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O3 -O3 _test_1.c -lm
$ ./test_O3 -1.7318E-306 +0.0 +1.3481E-317 +0.0 +0.0 +1.2605E232 +0.0 -1.3125E-306 +1.0497E-316 -0.0 +1.6345E-306 -1.4350E306 -1.1637E306 -0.0 -1.4425E-306 -1.0964E279
-7.41161839115463e-299
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/* This is a automatically generated test. Do not modify */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void compute(double comp, double var_1, double var_2, double var_3,
             double var_4, double var_5, double var_6, double var_7,
             double var_8, double var_9, double var_10, double var_11,
             double var_12, double var_13, double var_14, double var_15) {
  if ((long double)comp < +1.6891E-313 * pow((-0.0 / ((long double)var_1 * -1.9760E305)), +1.3503E-312)) {
    comp = var_2 * log10((+0.0 - +1.1097E305));
    double tmp_1 = var_3 * (var_4 / var_5);
    comp = tmp_1 / fmod(-1.9071E218 / +1.5967E79, (-1.8774E-318 - var_6));
    if (comp >=
        +0.0 * (var_7 + sqrt(var_8 - (var_9 * (-1.7114E-307 * var_10))))) {
      comp += (var_11 / -1.7618E-307 * var_12 - -1.4991E-307);
      comp = var_13 + var_14 / sin((-1.8183E-66 - (+1.1782E306 * -1.6519E-314 +
                                                   (var_15 * -1.1623E-311))));
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
  double tmp_12 = atof(argv[12]);
  double tmp_13 = atof(argv[13]);
  double tmp_14 = atof(argv[14]);
  double tmp_15 = atof(argv[15]);
  double tmp_16 = atof(argv[16]);

  compute(tmp_1, tmp_2, tmp_3, tmp_4, tmp_5, tmp_6, tmp_7, tmp_8, tmp_9, tmp_10,
          tmp_11, tmp_12, tmp_13, tmp_14, tmp_15, tmp_16);

  return 0;
}
