// This is the minimal test extracted by hand.


 
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
  double var_1 = +0.0;
  double var_2 = -0.0;
  double var_3 = -1.4801E305;
  double tmp = var_1 / +1.4859E-310 + (var_2 * atan2(var_3 / -1.8131E-319, -1.0247E305));
  printf("%.17g\n", tmp);

  return 0;
}
