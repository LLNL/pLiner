//quartz2962_37431/_tests/_group_8/_test_6.c
//-1.6970E53 5 5 5 -1.0077E-316 +1.1397E-307 -1.0416E306 +0.0 -0.0 +1.4662E262
//

/* This is a automatically generated test. Do not modify */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void compute(double comp, int var_1,int var_2,int var_3,double var_4,double var_5,double var_6,double var_7,double var_8,double var_9) {
for (int i=0; i < var_1; ++i) {
  for (int i=0; i < var_2; ++i) {
    for (int i=0; i < var_3; ++i) {
      if (comp <= cosh(-1.5365E-307)) {
        double tmp_1 = -1.5087E305;
comp += tmp_1 - (-1.4517E305 * (-1.3126E-306 / -1.4000E305 / -1.8397E-307));
comp = (long double)var_4 - (long double)var_5 / atanl((long double)var_6 / -0.0 / (long double)var_7 + sqrtl(((long double)var_8 * +1.4655E305 / (long double)var_9 - -1.7981E-317)));
}
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
  int tmp_4 = atoi(argv[4]);
  double tmp_5 = atof(argv[5]);
  double tmp_6 = atof(argv[6]);
  double tmp_7 = atof(argv[7]);
  double tmp_8 = atof(argv[8]);
  double tmp_9 = atof(argv[9]);
  double tmp_10 = atof(argv[10]);

  compute(tmp_1,tmp_2,tmp_3,tmp_4,tmp_5,tmp_6,tmp_7,tmp_8,tmp_9,tmp_10);

  return 0;
}
