// This is the minimal test extracted by hand.


 
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
  double x = -1.3864E-322; 
  double z = x / -0.0 * -0.0; 
  printf("%.3g / -0.0 * -0.0 = %.3g\n", x, z);		

  return 0;
}
