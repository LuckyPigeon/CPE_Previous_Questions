https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2296

#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

// 變數 n 原數字，變數 r 是取 mod 值，變數 odd 是判斷是否是基數
struct Num {
 int n,r;
 bool odd;
};

// 排列的規則
bool comp(const Num& a, const Num& b) {
 bool flag = false; // 判斷 a 和 b 是否要交換
 if(a.r < b.r) flag = true; // 如果餘數比較大放前面
 // 如果餘數相等
 else if(a.r == b.r) {
  if (a.odd && !b.odd) flag = true; // 如果基數就放前
  else if (!a.odd && b.odd) flag = false; // 如果是偶數舊部交換
  else if (a.odd && b.odd) flag = (a.n > b.n); // 如果兩個都是基數，原數比較大放前面
  else flag = (a.n < b.n); // 如果是兩個偶數，袁術比較小放前面
 }
 return flag; // 回傳是否交換 
}

int main() {
 int n,m,t; // 變數 n 代表有多少筆數據，變數 m 是 mod 值， 變數 t 是數據的暫存地  
 Num a[10000];// 陣列 a 數據的儲存
 while (cin >> n >> m && !(n == 0 && m == 0)) {
  cout << n << " " << m << endl;// 輸出 n 和 m
  for (int i = 0; i < n; i++) {
   cin >> t;
   a[i].n = t; // 紀錄原數字
   a[i].r = t%m; // 算 mod 值
   if(t%2 != 0) a[i].odd = true; // 判斷原數字是否是基數
   else a[i].odd = false;
  }
  sort(a, a + n,comp); // 開始排列
  for (int i = 0; i < n; i++)
   cout << a[i].n << endl; // 輸出結果
 }
 cout << "0 0" << endl; // 最後輸出兩個 0
 return 0;
}
