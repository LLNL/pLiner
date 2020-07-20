#include<stdio.h>

void foo2(double* x, double* y){
  *x += 1;
  *y += 2;
}

void foo1(double* x){
  *x += 1;
}

int main(){
  double a = 100;
  double b = 200;
  double c[2];

  c[0]=1;
  c[1]=2;
  foo1(&a);
  foo2(&a, &b);

  printf("a=%lf, b=%lf\n", a, b);

  return 0;
}
