// This is the minimal test extracted by hand.


 
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

//void compute(x, comp){
void compute(){
  double x = -1.6381E-322;
  double comp = +1.9797E-307; 
  int i;
  for (i=0; i<1; i++){
    comp += +1.0492E305 + x / -1.3627E-314;
    printf("%.3g\n", comp);
  }		
}

int main(){
  //compute(x, comp);
  compute();
  return 0;
}
