https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=889

#include<iostream>
using namespace std;
int main() {
  int f[40] = {0, 1}; //宣告一個 integer 陣列 f 長度為 40, 並賦值 0,1 給前兩位
  for(int k = 2; k < 40; k++) //用 for 迴圈從第 3 位將第 k 位值設為前兩位相加直到陣列滿
    f[k] = f[k - 1] + f[k - 2];
  int n;
  cin >> n; //輸入一個 integer n 為測資數量 
  while(n--) { //當 n-1 不是 0 ,就進到 while 迴圈 
    int m;
    cin >> m; //輸入一個 integer m 為測資
    cout << m << " = "; //輸出"m = "為格式需求
    bool preone = false; //宣告一個 bool preone 並給 false 的值
  for(int k = 39; k >= 2; k--) { //用 for 迴圈從 f 陣列，最後位開始比對
    if(m >= f[k]) //如果測資大於 f 陣列第 k 位，將輸入的數字減去費氏數列的數，並輸出 1 找到第一個 1 ，之後才可以輸出 0，所以將preone設為 true
     cout << "1"; 
     m -= f[k]; 
     preone = true; 
    }
    else if(preone) { 
     cout << "0";
    }
   }
   cout << " (fib)" << endl; //輸出" (fib)"為格式需求
 }
 return 0;
}
