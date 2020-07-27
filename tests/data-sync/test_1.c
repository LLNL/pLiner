// data sync: foo(&c[0], &c[1])

#include<stdio.h>

void foo(double* x, double* y){
  *x += 1;
  *y += 2;
}

int main(){
  double a = 100;
  double b = 200;
  double c[2];

  c[0]=1;
  c[1]=2;
  foo(&c[0], &c[1]);

  printf("c = [%lf, %lf]\n", c[0], c[1]);

  return 0;
}
