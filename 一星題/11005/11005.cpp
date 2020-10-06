https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1946


#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int f(int a, int b, int arr[], int &cnt) {
 int tmp[40] = {}, i;
 cnt = 0;
 while(a >= b) {
  tmp[cnt++] = a % b;
  a /= b;
 }
 if(a)
  tmp[cnt++] = a;
 for(i = 0; i < cnt; ++i)
  arr[cnt-i-1] = tmp[i];
 return 0;
}
int CalCost(int arr[], int cnt, int cost[]) {
 int sum = 0;
 for(int i = 0; i < cnt; ++i) {
  sum += cost[arr[i]];
 }
 return sum;
}
int main()
{
 int a, b, n, num, Min;
 int cost[40];
 int t, ti = 0;
 cin >> t;
 while(ti++ < t) {
  printf("Case %d:\n", ti);
  for(int i = 0; i < 36; ++i)
   cin >> cost[i];
  cin >> n;
  while(n--) {
   int arr[40] = {}, cnt = 0;
   int price[40] = {};
   cin >> num;
   Min = 999999999;
   for(b = 2; b <= 36; ++b) {
    f(num, b, arr, cnt);
    price[b] = CalCost(arr, cnt, cost);
    if(price[b] < Min)
     Min = price[b];
   }
   printf("Cheapest base(s) for number %d:", num);
   for(b = 2; b <= 36; ++b) {
    if(price[b] == Min)
     printf(" %d", b);
   }
   printf("\n");
  }
  if(ti != t)
   printf("\n");
 }
 return 0;
}