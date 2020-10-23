https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1131

#include <iostream>
using namespace std;

int main() {
 int n, m; // 宣告整數 n , m
 while(cin >> n >> m) { // while 輸入 n , m
  if(n < 2 || m < 2) { // 如果 n 小於 2 ,或是 m 小於 2 ,則 Boring
   cout << "Boring!\n";
   continue;
  }

  int arr[40] = {}; // 宣告 arr 陣列來紀錄 n 一直除以 m 的結果
  int Cnt = 0; // 宣告 Cnt 來紀錄總共計算了幾次
  while(n % m == 0) { // 如果 n 除以 m 還能整除,則繼續進行
   arr[Cnt++] = n; // 紀錄每次的 n
   n /= m; // 每執行完一次,讓 n 的質除以 m
  }

  if(n != 1) // 如果最後的 n 質不等於 1 ,則 Boring
   cout << "Boring!\n";
  else { // 
   for(int i = 0; i < Cnt; ++i)
    cout << arr[i] << " ";
   cout << "1" << endl;
  }
 }
 return 0;
}
