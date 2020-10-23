https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1131

#include <iostream>
using namespace std;

int main() {
 int n, m;                          // 宣告整數 n 、 m 
 while(cin >> n >> m) {             // 輸入整數 n 、 m
  if(n < 2 || m < 2) {              // 如果 n 或 m 小於 2 ， 輸出 " Boring! " ， 且重新回到上方的 while 判斷式
   cout << "Boring!\n";
   continue;             
  }

  int arr[40] = {};                 // 宣告整數陣列 arr ， 陣列元素初始化為 0 
  int Cnt = 0;                      // 宣告整數 Cnt ， 數值為 0
  while(n % m == 0) {               // 判斷 n 除以 m 的餘數是否為 0 
   arr[Cnt++] = n;                  // 若餘數為 0 ， 陣列 arr 的 Cnt + 1 號元素設為 n
   n /= m;                          // 將 n 值改為 n 除以 m 
  }                                 // 重複執行至 n 除以 m 的 餘數不等於 0

  if(n != 1)                        // 判斷 n 是否為 1 
   cout << "Boring!\n";             // 若 n 不為 1 ， 輸出 " Boring! "
  else {                            // 若 n 為 1 ， 進入 for 迴圈
   for(int i = 0; i < Cnt; ++i)     // 從 i = 0 開始 ， 且進入迴圈前 i 需先 + 1 ， 判斷 i + 1 是否小於 Cnt 後方可繼續執行迴圈  
    cout << arr[i] << " ";          // 輸出 陣列 arr 的第 i 個元素和空格
   cout << "1" << endl;             // for 迴圈結束後輸出 1 
  }
 }
 return 0;
}
