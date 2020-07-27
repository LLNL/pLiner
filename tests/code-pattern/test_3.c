// code pattern: for-if-else

#include<stdio.h>

int main(){
  double a = 100;
  double b = 200;
  double c[2];

  for(int i=0; i<2; i++)
    if (a>b)
      c[i] = a-b;
    else
      c[i] = b-a;
 
  printf("c = [%lf, %lf]\n", c[0], c[1]);

  return 0;
}
