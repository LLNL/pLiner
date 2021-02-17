//quartz2962_37437/_tests/_group_6/_test_9.c
//+1.9207E-323 5 5 -0.0 -1.3629E20 +1.7272E-134 -1.6158E-311 -1.5581E-323 +1.1476E0 -0.0
//

/* This is a automatically generated test. Do not modify */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void compute(double comp, int var_1,int var_2,double var_3,double var_4,double var_5,double var_6,double var_7,double var_8,double var_9) {
for (int i=0; i < var_1; ++i) {
  if ((long double)comp > (-1.0504E-306 * ((long double)var_3 * (long double)var_4))) {
    for (int i=0; i < var_2; ++i) {
      double tmp_1 = tanh(sqrt(var_5 * var_6 / var_7 * -1.7260E96));
comp = tmp_1 * var_8 - +0.0;
comp = (+1.7213E306 + (+0.0 - var_9 - -1.1113E-71));
}
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
  int tmp_2 = atoi(argv[2]);
  int tmp_3 = atoi(argv[3]);
  double tmp_4 = atof(argv[4]);
  double tmp_5 = atof(argv[5]);
  double tmp_6 = atof(argv[6]);
  double tmp_7 = atof(argv[7]);
  double tmp_8 = atof(argv[8]);
  double tmp_9 = atof(argv[9]);
  double tmp_10 = atof(argv[10]);

  compute(tmp_1,tmp_2,tmp_3,tmp_4,tmp_5,tmp_6,tmp_7,tmp_8,tmp_9,tmp_10);

  return 0;
}
