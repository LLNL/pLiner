// This is the minimal test extracted by hand.


 
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
  double var_1 = +1.5539E305; 
  double var_2 = -1.1615E98;
  double tmp = -1.2482E-57 - var_1 * var_2 * -0.0;
  printf("%.17g\n", tmp);

  return 0;
}
