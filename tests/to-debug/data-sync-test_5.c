// data sync: double ret=foo(&a, &b)

#include<stdio.h>

double foo(double* x, double* y){
  *x += 1;
  *y += 2;
  return *x+*y;
}

int main(){
  double a = 100;
  double b = 200;
  double c[3];

  double ret = foo(&a, &b);

  c[0]=a;
  c[1]=b;
  c[2]=ret;
  printf("c[0]=%lf, c[1]=%lf, c[2]=%lf\n", c[0], c[1], c[2]);

  return 0;
}
