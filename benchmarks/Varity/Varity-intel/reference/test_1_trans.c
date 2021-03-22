//quartz2963_6809/_tests/_group_4/_test_7.c
//-1.8202E-306 5 5 -1.2312E-320
//

/* This is a automatically generated test. Do not modify */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void compute(double comp, int var_1,int var_2,double var_3) {
long double comp_12_16_H = comp;
for (int i=0; i < var_1; ++i) {
  for (int i=0; i < var_2; ++i) {
    comp_12_16_H += ((long double)var_3 / -1.2309E-151);comp = comp_12_16_H;
    
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

  compute(tmp_1,tmp_2,tmp_3,tmp_4);

  return 0;
}
