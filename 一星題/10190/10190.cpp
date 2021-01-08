https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1131

#include <iostream>
using namespace std;

int main() {
 int n, m;
 while(cin >> n >> m) {  //當輸入n(被除數)、m(除數)時繼續執行
  if(n < 2 || m < 2) {  //避免n或m小於2，後面n/m不斷整除，進入無窮迴圈
   cout << "Boring!\n";
   continue;  //輸出結果，結束此次迴圈，回到while繼續下次n,m輸入
  }

  int arr[40] = {}; //用來存輸出結果
  int Cnt = 0; //arr的index
  while(n % m == 0) { 
   arr[Cnt++] = n; //若n/m餘零(代表可以整除)，將n存到陣列，arr的index+1
   n /= m;  //將n/m才能繼續檢查這次結果能不能繼續被整除
  }

  if(n != 1)  //最後一個結果非1
   cout << "Boring!\n";
  else {
   for(int i = 0; i < Cnt; ++i)  //最後結果是1，將陣列輸出
    cout << arr[i] << " ";
   cout << "1" << endl;
  }
 }
 return 0;
}
