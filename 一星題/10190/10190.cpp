https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1131

#include <iostream>
using namespace std;

int main() {
 int n, m; //宣告2個 integer 變數
 while(cin >> n >> m) { //當有輸入 2 個值才會進到 while 迴圈
  if(n < 2 || m < 2) { //如果兩個輸入值小於 2 輸出 "Boring!"
   cout << "Boring!\n";
   continue;
  }

  int arr[40] = {}; //宣告1個 char 陣列 arr
  int Cnt = 0; //宣告1個 integer 變數 Cnt = 0
  while(n % m == 0) { //n 可以被 m 整除，進到 while 迴圈
   arr[Cnt++] = n; //arr 陣列第 Cnt 格存放值為 n，Cnt 值加 1
   n /= m; // n 除 m 的值，存放在 n
  }

  if(n != 1) //最終 n 不等於 1 輸出 "Boring!"
   cout << "Boring!\n";
  else { //n 等於 1，從 arr 的第 0 格開始輸出到第 Cnt 格，最後輸出1
   for(int i = 0; i < Cnt; ++i)
    cout << arr[i] << " ";
   cout << "1" << endl;
  }
 }
 return 0;
}
