// code pattern: if-else

#include<stdio.h>

int main(){
  double a = 100;
  double b = 200;
  double c[2];

  if (a>b)
    c[0] = a;
  else
    c[0] = b;
  c[1] = c[0];
 
  printf("c = [%lf, %lf]\n", c[0], c[1]);

  return 0;
}
