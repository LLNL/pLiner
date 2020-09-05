//quartz2962_37427/_tests/_group_8/_test_4.c
//-1.8704E305 5 +1.7575E180 -1.2241E-132 -1.5490E-212 +0.0 +1.1296E306 +1.8628E-306 +1.5591E-321 +1.5873E-180
//

/* This is a automatically generated test. Do not modify */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void compute(double comp, int var_1,double var_2,double var_3,double* var_4,double var_5,double var_6,double var_7,double var_8,double var_9) {
double tmp_1 = -1.7937E-307;
comp += tmp_1 / +1.8455E305 + (-0.0 / (+1.1259E-311 + +0.0));
comp += tanh(-0.0 * var_2 * (-1.1210E-307 * var_3 + +1.0844E143));
for (int i=0; i < var_1; ++i) {
  var_4[i] = (-0.0 * (var_5 * var_6));
comp = var_4[i] - (-1.9509E-307 + -1.5690E-319);
long double comp_18_18_H = comp;
comp_18_18_H += atan2l((long double)var_7 / (-0.0 + atan2l(+1.5697E305, +0.0)), (long double)var_8 / (long double)var_9);comp = comp_18_18_H;

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
  double* tmp_5 = initPointer( atof(argv[5]) );
  double tmp_6 = atof(argv[6]);
  double tmp_7 = atof(argv[7]);
  double tmp_8 = atof(argv[8]);
  double tmp_9 = atof(argv[9]);
  double tmp_10 = atof(argv[10]);

  compute(tmp_1,tmp_2,tmp_3,tmp_4,tmp_5,tmp_6,tmp_7,tmp_8,tmp_9,tmp_10);

  return 0;
}
