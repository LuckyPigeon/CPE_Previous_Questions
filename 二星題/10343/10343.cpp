https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=192

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int n;
int check(int k) {
  int i, a, h, j;
  j = k * k;
  if(j != 0)
    a = log10(j);
  else
    a = 0;
  if(a == n)
    return 0;
  h = pow(10, n / 2);
  if((j / h + j % h) == k)
    return 1;
  else
    return 0;
}
void out(int k) {
  int i, a, h;
  if(a != 0)
    a = log10(k);
  else
    a = 0;
  for(int j = a; j < n-1; j++)
    printf("0");
  printf("%d\n", k);
}
int main() {
  int a;
  while(scanf("%d", &n) == 1) {
    a = (int) (pow(10, n / 2)) * 2 - 2;
    for(int i = 0; i < a; i++)
      if(check(i))
        out(i * i);
  }
  return 0;
}