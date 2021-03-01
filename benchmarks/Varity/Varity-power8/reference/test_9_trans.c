/* command----------------------------------------------------------------lassen742_4692/_tests/_group_5/_test_5.c 
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O0 -O0 test.c -lm
$ ./test_O0 -1.1687E305 -1.5181E-322 -1.4252E-321 -1.0769E305 +0.0 5 +1.9594E-307 -1.2721E282 -1.7849E-306 +1.3279E-307 +1.9550E-323
808343999146
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O3 -O3 test.c -lm
$ ./test_O3 -1.1687E305 -1.5181E-322 -1.4252E-321 -1.0769E305 +0.0 5 +1.9594E-307 -1.2721E282 -1.7849E-306 +1.3279E-307 +1.9550E-323
nan
--------------------------------------------------------------------------*/


/* This is a automatically generated test. Do not modify */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void compute(double comp, double var_1,double var_2,double var_3,double var_4,int var_5,double var_6,double var_7,double var_8,double var_9,double var_10) {
if (comp <= (var_1 - (var_2 / -1.5224E306 / var_3 - var_4))) {
  double tmp_1 = (+1.3355E306 * (+1.8560E-323 * cos(log(var_6 * +1.4540E305))));
comp += tmp_1 + (+0.0 * var_7);
for (int i=0; i < var_5; ++i) {
  double tmp_2 = (var_8 * var_9);
comp = (long double)tmp_2 + (-1.5975E-311 / (-0.0 - ((long double)var_10 - +0.0)));
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
  int tmp_6 = atoi(argv[6]);
  double tmp_7 = atof(argv[7]);
  double tmp_8 = atof(argv[8]);
  double tmp_9 = atof(argv[9]);
  double tmp_10 = atof(argv[10]);
  double tmp_11 = atof(argv[11]);

  compute(tmp_1,tmp_2,tmp_3,tmp_4,tmp_5,tmp_6,tmp_7,tmp_8,tmp_9,tmp_10,tmp_11);

  return 0;
}
