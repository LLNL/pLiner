// code pattern: for-stmt

#include<stdio.h>

int main(){
  double a = 100;
  double b = 200;
  double c[2];

  for(int i=0; i<2; i++)
    c[i] = a+b;
 
  printf("c = [%lf, %lf]\n", c[0], c[1]);

  return 0;
}
