#include<stdio.h>

double foo(double* x, double* y){
  *x += 1;
  *y += 2;
  return *x+*y;
}

int main(){
  double a = 100;
  double b = 200;
  double c[2];
  double ret;

  c[0]=1;
  c[1]=2;
  ret = foo(&a, &b)+foo(&a, &b);

  printf("a=%lf, b=%lf, ret=%lf\n", a, b, ret);

  return 0;
}
