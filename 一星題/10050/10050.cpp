// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=991

#include <iostream>
using namespace std;

/*
 * 題目說明
 * 題目給「總天數」和「各個政黨罷會的間隔天數」，本題要模擬出這些日子中有幾天是罷會的天數（週五、週六不算）
 * 
 * Input: 
 *      先給一個整數 T 代表有幾筆測資
 *      每個測資第一行都有一個整數 N ，代表需要模擬的總天數
 *      接著是一個整數 P ，代表有幾個政黨
 *      接下來的 P 行都是整數 hi ，代表第 i 個政黨的間隔天數
 * 
 * Output:
 *      輸出每筆測資的罷會天數
*/

int main() {
 int dataNum, day, political, *noWork, ans; 
 // 分別為 測資數量、該筆測資需要模擬的總天數、政黨數、指標(稍後會用來建立動態陣列，用來儲存政黨的間隔日）、答案
 
 bool *eachDays;    // 紀錄各個天數的罷會狀態(稍後會用來建立動態陣列）

 cin >> dataNum; // 讀取測資數量
 for(int d = 0; d < dataNum; d++) { // 讀取 dataNum 個 （ 迴圈內處理每筆個資 ）
  cin >> day >> political;  // 讀取「模擬天數」以及「政黨數量」

  ans = 0;  // 將答案先歸零，因為接下來要計算罷會日
  noWork = new int [political]; // 動態建立長度等於「政黨數」的整數陣列，稍後要用來儲存各個政黨的間隔天數
  eachDays = new bool [day];    // 動態建立長度等於「模擬總天數」的 bool 陣列，要用來紀錄哪些日子被模擬為「罷會日」 
  for(int i = 0; i < day; i++)  // 要先把「模擬總天數」的罷會狀態都先設定為 False
   eachDays[i] = false;

  for(int i = 0; i < political; i++) // 讀取各個政黨的「罷會間隔天數」
   cin >> noWork[i];

  for(int i = 0; i < political; i++) // 各個依序進行，因為等一下要一一模擬罷會的日子 
   for(int j = noWork[i] - 1; j < day; j += noWork[i]) // 每一次都間隔 nowork[輪到的政黨的 index ] 天
    eachDays[j] = true; // 將該政黨要罷會的那一天設定為 true

  for(int i = 0; i < day; i++)  // 將所有模擬天數的罷會狀態一一讀取進來，若為 true 就是罷會日，反之亦然，
   if(eachDays[i] && i % 7 != 5 && i % 7 != 6)  // 若該天為 true 且 那天不是週五或週六就把答案數量 +1
    ans++;

  delete [] noWork;     // 將動態產生的陣列 noWork 從記憶體中刪除
  delete [] eachDays;   // 將動態產生的陣列 eachDays 從記憶體中刪除
  cout << ans << endl;  // 顯示 Ouput 
 }

 return 0;
}
