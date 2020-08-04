// data sync: pointer analysis

#include<stdio.h>

int main(){
  double a=100;
  double *p;
  double c[1];

  p = &a;
  *p = *p +1;
  c[0]=a;
  printf("c[0] = %lf\n", c[0]);

  return 0;
}
