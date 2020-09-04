/* command----------------------------------------------------------------lassen566_25176/_tests/_group_6/_test_2.c
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O0 -O0 test.c -lm
$ ./test_O0 -1.5906E305 5 -1.8004E-312 +1.0053E305 -1.7666E115 +1.4902E-65 -1.1552E-316 +1.8210E306
1
$ /usr/tce/packages/xl/xl-2019.02.07/bin/xlc -o test_O3 -O3 test.c -lm
$ ./test_O3 -1.5906E305 5 -1.8004E-312 +1.0053E305 -1.7666E115 +1.4902E-65 -1.1552E-316 +1.8210E306
nan
--------------------------------------------------------------------------*/


/* This is a automatically generated test. Do not modify */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void compute(double comp, int var_1,double var_2,double var_3,double var_4,double var_5,double var_6,double var_7) {
comp += var_2 - +1.5498E-322;
double tmp_1 = +1.9932E-320;
comp += tmp_1 + log10(-1.0706E266);
for (int i=0; i < var_1; ++i) {
  comp = var_3 * sinh(+1.0173E-307);
comp = -1.6793E306 / floorl((long double)var_4 / +1.8764E-307 + -1.2201E-323);
comp += ceil(+1.3910E-306);
}
if (comp == +1.9296E-306 + (+1.5882E-6 * +1.3719E-232 * -1.1533E305 - -1.6211E-307)) {
  comp += (var_5 + +1.4717E44 / var_6);
comp = +1.2771E-46 - (var_7 * +1.6157E-307);
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

  compute(tmp_1,tmp_2,tmp_3,tmp_4,tmp_5,tmp_6,tmp_7,tmp_8);

  return 0;
}
