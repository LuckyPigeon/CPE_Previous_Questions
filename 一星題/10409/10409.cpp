#include <iostream> 
#include <string> 
using namespace std; 
int main() {
 int m; // 儲存使用者將要給予指令的數量
 /* 連續輸入 m */
 while (cin >> m){
  /* 如果 m 小於 0 結束程式 */
  if (m <= 0)
   break; 
  
  int u = 1, n = 2, w = 3, e = 4, s = 5, o = 6; // 骰子的初始狀態 上(u = 1)，北(n = 3)，西(w = 3)，下(o = 6)，東(e = 4)，南(s = 5)
  /* 逐一輸入指令 */
  for (int i = 0; i < m; i++){
   string stg; // 宣告字串 stg，用來存取使用者所輸入的指令
   int t; // 宣告整數 t，用來暫存指令
   cin >> stg; // 數入指令
   /* 判斷指令的第一個字元，並改變骰子上下東西南北的數字 */
   switch (stg[0]){
    /* 如果是 n */ 
    case 'n':
     t = u; 
     u = s; 
     s = o; 
     o = n; 
     n = t; 
     break; 
    /* 如果是 s */ 
    case 's':
     t = u; 
     u = n; 
     n = o; 
     o = s; 
     s = t; 
     break; 
    /* 如果是 e */
    case 'e':
     t = u; 
     u = w; 
     w = o; 
     o = e; 
     e = t; 
     break; 
    /* 如果是 w */
    case 'w':
     t = u; 
     u = e; 
     e = o; 
     o = w; 
     w = t; 
     break; 
   }
  }
  cout << u << endl; // 輸出骰子上方最終的數字
 }
 return 0; 
}
