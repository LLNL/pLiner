// This is the minimal test extracted by hand.


 
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
  double x=0.1;
  double y=0.0/0.0;
  double z = x + -0.0 * y; 
  printf("%.3g + -0.0 * %.3g = %.3g\n", x, y, z);		

  return 0;
}
