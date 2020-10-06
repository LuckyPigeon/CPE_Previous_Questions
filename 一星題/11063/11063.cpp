https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2004

#include <stdio.h>
int main() {
 int b[100], n, i, j, t = 1, flag;
 int check[20001];

 while(scanf("%d", &n) == 1)
 {
  flag = 1;
  for(i = 0; i < 20001; i++)
   check[i] = 0;
  for(i = 0; i < n; i++) {
   scanf("%d", &b[i]);
   if(b[i] < 1)
    flag = 0;
  }

  for(i = 0; i < n; i++)
   for(j = i;j < n; j++) {
    if(check[b[i] + b[j]] || b[j] < b[i])
     flag = 0;
    else
     check[b[i] + b[j]]=1;
   }
  if(flag)
   printf("Case #%d: It is a B2-Sequence.\n\n",t++);
  else
   printf("Case #%d: It is not a B2-Sequence.\n\n",t++);
 }
 return 0;
}