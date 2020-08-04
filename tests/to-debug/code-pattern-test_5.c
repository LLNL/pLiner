// code pattern: static qualifier

#include<stdio.h>

int main(){
  static double a;
  double c[1];

  c[0]=a;
  printf("c[0] = %lf\n", c[0]);

  return 0;
}
