// This is the minimal test extracted by hand.


 
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
  double x=0.1;
  double y=0.0/0.0;

  if (x >= y){
    printf("%.3g >= %.3g holds\n", x, y);		
  } else {
    printf("%.3g >= %.3g does not hold\n", x, y);		
  }

  return 0;
}
