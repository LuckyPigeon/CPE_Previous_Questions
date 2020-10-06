https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1078

#include <iostream>
#include <cstdio>
using namespace std;
int main() {
 int n;
 while(cin >> n && n) {
  int arr[1000] = {};
  int x, y, sum = 0;
  for(int i = 0; i < n; i++) {
   scanf("%d.%d", &x, &y);
   arr[i] = x * 100 + y;
   sum += arr[i];
  }
  int avg;
  if(sum % n)
   avg = sum / n + 1;
  else
   avg = sum / n;
  int avt = sum / n;
  int dif = 0, dif2 = 0;
  for(int i = 0; i < n; i++) {
   if(arr[i] > avg)
    dif += (arr[i] - avg);
   else if(arr[i] < avt)
    dif2 += (avt - arr[i]);
  }
  if(dif > dif2)
   printf("$%d.%02d\n", dif / 100, dif % 100);
  else
   printf("$%d.%02d\n", dif2 / 100, dif2 % 100);
 }
 return 0;
}