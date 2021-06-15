// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1042
#include <iostream>
#include <iomanip>
using namespace std;
/*
 * 題目說明
 * Bangla Number 是用文字表示數字，其實就是簡單的單位代換
 * 題目輸入一個數字，必須用 Bangla Number 的形式輸出
 * 
 * Input:
 *      有多筆測資，每筆測資只輸入一個非負整數 <=999999999999999
 * 
 * Output:
 *      每筆測資都需要輸出測資編號以及 Bangla Number 的形式
 *      Ex: 1. 23 hajar 7 shata 64
 * 
 */

void kuti(long long int num)    // 逐步將整數代換為 Bangla Number 的形式的 function
{
 if(num>=10000000)  // 先代換 kuti 位數
 {
  kuti(num/10000000);   // 丟進 function 處理輸出，該數值在 kuti function 執行，處理大於 kuti 的數值該如何再轉成 Bangla Number
  cout<<" kuti";        // 前一行輸出 kuti 位數的數值，這裡將 kuti 位數的名稱輸出
  num%=10000000;        // 處理完 kuti 位數後，需要取餘數算下一個的 "lakh" 位數
 }
 if(num>=100000)        // 接著處理 lakh 位數
 {
  kuti(num/100000);     // 與處理 "kuti" 位數方式相同，為了輸出 lakh 位數的數值
  cout<<" lakh";        // 輸出 lakh 位數的名稱
  num%=100000;          // 處理完 lakh 位數，接下來處理 hajar 位數
 }
 if(num>=1000)          // 與 kuti, lakh 的位數處理功能相同，下略
 {
  kuti(num/1000);
  cout<<" hajar";
  num%=1000;
 }
 if(num>=100)           // 與 kuti, lakh 的位數處理功能相同，下略
 {
  kuti(num/100);
  cout<<" shata";
  num%=100;
 }
 if(num)                // 為了輸出小於 shata 的位數
 {
  cout<<" "<<num;
 }
}
int main()
{
 long long int n;   // 測資個數
 int time=1;        // 該測資的編號
 while(cin>>n)      // 讀取測資個數
 {
  cout<<setw(4)<<time<<"."; // 輸出測資編號
  if(n==0)                  // 若輸入為 0 ，轉為 Bangla Number 也為 0 ，直接輸出即可
  {
   cout<<" 0"<<endl;        // 直接輸出 0
   time++;                  // 處理完一筆測資，將測資編號 +1
  }
  else                      // 處理非 0 數值
  {
   kuti(n);                 // 丟入 kuti function ，直接輸出 Bangla Number
   time++;                  // 處理完一筆測資，將測資編號 +1
   cout<<endl;
  }
 }
}


// https://jennaweng0621.pixnet.net/blog/post/403629785-CPE%E9%A1%8C%E7%9B%AE%E7%9B%AE%E9%8C%84%E5%8F%8A%E8%A7%A3%E7%AD%94
// http://jennaweng0621.pixnet.net/blog/category/6372301