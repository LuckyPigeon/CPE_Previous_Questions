https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2004

#include <stdio.h>
int main() {
 int b[100], n, i, j, t = 1, flag;  //初始化t=1，用來計算是第幾次結果
 int check[20001];

 while(scanf("%d", &n) == 1)  //若有輸入n，繼續執行迴圈
 {
  flag = 1;  //初始化flag
  for(i = 0; i < 20001; i++)
   check[i] = 0;  //初始化check陣列為0
  for(i = 0; i < n; i++) {
   scanf("%d", &b[i]);  //將輸入的數字存進b陣列
   if(b[i] < 1)
    flag = 0;  //若輸入的數字小於1，flag設為0
  }

  for(i = 0; i < n; i++)
   for(j = i;j < n; j++) {
    if(check[b[i] + b[j]] || b[j] < b[i])  //任兩個數相加和出現過 或 b[j]比b[i]小，flag設0
     flag = 0;
    else
     check[b[i] + b[j]]=1;  //任兩數和沒出現過，在check裡index兩數和的位置設1
   }
  if(flag)  //flag是1時，輸出字串，且t+1次
   printf("Case #%d: It is a B2-Sequence.\n\n",t++);
  else  //flag是0時，輸出字串，且t+1次
   printf("Case #%d: It is not a B2-Sequence.\n\n",t++);
 }
 return 0;
}
