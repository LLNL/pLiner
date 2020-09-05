// This is the minimal test extracted by hand.


 
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void compute(){
  double x, y, z, comp;
  x = -1.6381E-322;
  y = +1.0492E305;
  z = -1.3627E-314;
  comp = +1.9797E-307; 
  comp += y + x / z;
  printf("%.3g\n", comp);
}

int main(){
  compute();
  return 0;
}
