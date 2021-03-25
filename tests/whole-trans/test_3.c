// data sync: foo1(&a); foo2(&a, &b)

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

  foo1(&a);
  foo2(&a, &b);

  c[0]=a;
  c[1]=b;
  printf("c[0]=%lf, c[1]=%lf\n", c[0], c[1]);

  return 0;
}
