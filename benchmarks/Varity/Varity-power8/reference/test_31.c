/* command----------------------------------------------------------------lassen374_133175/_tests/_group_5/_test_7.c
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O0 -O0 test.c -lm
$ ./test_O0 +1.5012E-318 +1.7211E-307 -1.5697E306 +1.0486E-310 +0.0 +1.5724E-306 -1.1530E47
1.0592469898706759e-95
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O3 -O3 test.c -lm
$ ./test_O3 +1.5012E-318 +1.7211E-307 -1.5697E306 +1.0486E-310 +0.0 +1.5724E-306 -1.1530E47
nan
--------------------------------------------------------------------------*/


/* This is a automatically generated test. Do not modify */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void compute(double comp, double var_1,double var_2,double var_3,double var_4,double var_5,double var_6) {
comp = +0.0 + (var_1 + (-1.6627E211 / var_2));
comp += (-1.4333E-264 + +1.2659E-197 / var_3 * var_4);
comp += (+1.2600E-311 / (var_5 + var_6));
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

  compute(tmp_1,tmp_2,tmp_3,tmp_4,tmp_5,tmp_6,tmp_7);

  return 0;
}
