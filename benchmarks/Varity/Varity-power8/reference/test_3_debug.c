// This is the minimal test extracted by hand.


 
#include <stdio.h>

void compute(){
  double x = -1.6381E-322;
  double comp = +1.9797E-307; 
  for (int i=0; i<1; i++){
    comp += +1.0492E305 + x / -1.3627E-314;
  }		
  printf("%.5g\n", comp);
}

int main(){
  compute();
  return 0;
}
