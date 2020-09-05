//quartz2962_37431/_tests/_group_8/_test_10.c
//-0.0 5 -1.9615E-307 -1.5526E-319 -1.0716E-306 -1.6152E-313 -1.3650E-306 -1.9967E306 +1.0917E-149
//

/* This is a automatically generated test. Do not modify */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void compute(double comp, int var_1,double* var_2,double var_3,double var_4,double var_5,double var_6,double var_7,double var_8) {
for (int i=0; i < var_1; ++i) {
  double tmp_1 = (var_3 + var_4);
var_2[i] = +1.5179E-323;
comp = var_2[i] + tmp_1 - (var_5 / (var_6 + var_7 / -1.0506E-323 + var_8));
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
  double* tmp_3 = initPointer( atof(argv[3]) );
  double tmp_4 = atof(argv[4]);
  double tmp_5 = atof(argv[5]);
  double tmp_6 = atof(argv[6]);
  double tmp_7 = atof(argv[7]);
  double tmp_8 = atof(argv[8]);
  double tmp_9 = atof(argv[9]);

  compute(tmp_1,tmp_2,tmp_3,tmp_4,tmp_5,tmp_6,tmp_7,tmp_8,tmp_9);

  return 0;
}
