https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1872

#include<iostream>
#include<stack> // 引入stack的標頭檔

using namespace std;

int main() {
 stack<int> st; // 建立堆疊 st
 int n; //宣告一個 integer 變數 n
 while(cin >> n && n){ //當輸入一個值 n ，且值大於 0，進 while 迴圈
   int parity = 0; //宣告一個 integer 變數 parity 等於 0
   while(n) { //當n值大於 0，進 while 迴圈
    parity += n % 2; //parity 等於 n 除 2 餘數加上 parity (目的為了算出有幾個1)
    st.push(n % 2); //st 疊上 n 除 2 餘數
    n /= 2; //n 等於 n 除 2 捨棄餘數的整數
   }
   cout << "The parity of "; 
   while(st.size()) { //當堆疊 st 長度大於 0，進 while 迴圈
    cout << st.top(); //輸出最上層
    st.pop(); //然後將最上層移除
   }
   cout << " is " << parity << " (mod 2).\n";
 }
 return 0;
}
