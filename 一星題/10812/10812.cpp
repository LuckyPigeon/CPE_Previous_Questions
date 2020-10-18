#include <iostream> 
using namespace std; 
int main() 
{ 
  /* 
    宣告整數 n，用來存取有幾筆資料。
    宣告整數 s ，用來紀錄兩數之和。
    宣告整數 d，用來紀錄兩數之差。
  */
  int n, s, d; 
  cin>>n; // 輸入有幾筆資料
  /* 逐一處理每筆資料 */
  for(int i=0; i<n; i++)
  {
    cin>>s>>d; // 輸入兩數之和、兩數之差
    /* 如果兩數之和大於兩數之差，且 s+d 除以 2 的餘數是 0，且 s-d 除以 2 的餘數是 0，就是有可能的資料 */
    if(s>d && ((s+d)%2==0) && ((s-d)%2==0))
      cout<<(s+d)/2<<" "<<(s-d)/2<<endl; // 輸出 s+d 除以 2 和 s-d 除以 2
    /* 如果 s 是 0 且 d 也是 0 */
    else if(s==0 && d==0)
      cout<<"0 0"<<endl; // 輸出 0 和 0
    /* 如果都無法滿足以上兩種條件 */
    else
      cout<<"impossible"<<endl; // 就輸出 impossible
  }
}
