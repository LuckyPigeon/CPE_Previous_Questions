https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=87

#include <stdio.h>
#include <stdlib.h>
int find(int n,int m) {
 int in[100], last, c, i, k;
 for(i = 0; i < 100; i++)
 in[i] = 0;
 for(i = 1, k = m, c = 0; c < n;) {
  if(!in[i] && i <= n) {
   if(k == m) {
    last = i;
    c++;
    k = in[i] = 1;
   }
   else {
    i++;
    k++;
   }
  }
  else {
   i++;
   if(i > n)
    i = 1;
  }
 }
 if(last == 13)
  return 1;
 return 0;
}
int main()
{
 int n,m;
 while(scanf("%d", &n) == 1 && n != 0) {
  for(m = 1; ; m++)
   if(find(n, m)) {
    printf("%d\n", m);
    break;
   }
 }
 return 0;
}