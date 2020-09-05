/* command----------------------------------------------------------------lassen125_48344/_tests/_group_8/_test_7.c
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O0 -O0 test.c -lm
$ ./test_O0 -1.6832E-310 5 +1.1339E305 -1.9735E-311 -1.0790E306 +1.9471E305 +1.2175E-307 -1.6189E-319 +0.0 +1.2167E-306 -1.2143E-186 +0.0 -1.0442E-307 +1.1241E-310 +1.8536E306 +1.4233E282 +1.6618E-311 
inf
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O3 -O3 test.c -lm
$ ./test_O3 -1.6832E-310 5 +1.1339E305 -1.9735E-311 -1.0790E306 +1.9471E305 +1.2175E-307 -1.6189E-319 +0.0 +1.2167E-306 -1.2143E-186 +0.0 -1.0442E-307 +1.1241E-310 +1.8536E306 +1.4233E282 +1.6618E-311
nan
--------------------------------------------------------------------------*/


/* This is a automatically generated test. Do not modify */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void compute(double comp, int var_1,double var_2,double var_3,double var_4,double var_5,double var_6,double var_7,double var_8,double var_9,double var_10,double var_11,double var_12,double var_13,double var_14,double var_15,double var_16) {
if (comp < (var_2 + -1.8696E-48)) {
  comp += (+1.4467E306 / sinh((var_3 - ldexp(var_4 - ldexp(-1.3819E-306 + (var_5 * +0.0), 2), 2))));
double tmp_1 = -1.2024E-322;
comp = tmp_1 * (+1.9117E-313 + +1.2404E-307);
if (comp < (var_6 - var_7)) {
  comp += (var_8 * var_9 + (var_10 / +1.5319E-322 * var_11));
}
for (int i=0; i < var_1; ++i) {
  comp = (+1.1891E306 * var_12);
comp += var_13 * (var_14 + (-1.4838E306 - +1.5947E-306));
comp += (var_15 / var_16);
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
  double tmp_17 = atof(argv[17]);

  compute(tmp_1,tmp_2,tmp_3,tmp_4,tmp_5,tmp_6,tmp_7,tmp_8,tmp_9,tmp_10,tmp_11,tmp_12,tmp_13,tmp_14,tmp_15,tmp_16,tmp_17);

  return 0;
}
