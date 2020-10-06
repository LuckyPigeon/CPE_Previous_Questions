https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1348

#include <cstdio>
#include <iostream>
using namespace std;

int ABS(int x) { return x < 0 ? -x : x; }
int GCD(int a, int b) { return b == 0 ? a : GCD(b, a%b); }

int main(void) {
 int num[1005], ans, i, j, n;
 
 while(scanf("%d", &num[0]) && num[0]) {
  n = 1; ans = 0;
  while(scanf("%d", &num[n]) && num[n])
   ++n;

  for(i = 0; i < n; ++i)
   for(j = i + 1; j < n; ++j)
    if(num[i] - num[j] != 0)
     ans = GCD(ABS(num[i] - num[j]), ans);

  printf("%d\n", ans);
 }
 return 0;
}