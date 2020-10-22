https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=998

#include <algorithm>
#include <iostream>

using namespace std;

int s[1000005]; // 宣告一個長 1000005 的 int 陣列 s
int main() // 主程式
{
  int n; // 宣告一個 int 變數 n
  while (cin>>n) // 輸入測資數量
  {
     for ( int i = 0 ; i < n ; ++ i )
        cin>>s[i]; // 利用 for 迴圈，跑 n 次，將測資存入 int 陣列 s
     sort(s, s+n); // 利用 sort function ，將 s 陣列做排序
     int val = s[(n-1)>>1], count = 0; // 宣告一個 int 變數 val ，內容是 s 陣列第 (n-1)/2 格的資料（也就是最接近中位數的資料）
     for ( int i = 0 ; i < n ; ++ i )
        count += (val==s[i] || s[i]==s[n>>1]); 
        /* 
           利用 for 迴圈，跑 n 次，如果 val 和 s[i] 相同或 
           s[i] 和 s 陣列第 n/2 格的資料相同， count 就加 1 
           也就是計算最接近中位數資料的個數
        */
     cout << val << " " << count << " " << (s[n>>1] - val + 1) << endl; 
        /*
            輸出結果 val 也就是中位數， count 也就是中位數個數， s[n>>1] - val + 1 為可能有幾種和中位數最相近的值
        */
  }
  return 0; // 結束主程式
}
