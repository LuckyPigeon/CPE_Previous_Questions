https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2091
#include <iostream>
using namespace std;
int main()
{
  int n, cola, sum; // 宣告三個 int 變數 n cola sum
  while(cin>>n) // 當輸入 n 執行 while 迴圈
  {
    if(1<=n && n<=200) // 如果小於 1 、大於 200 ，執行此 if
    {
      cola=n; // assign n 得值給 cola
      while(n>=3) // 當 n 大於等於 3 ，執行此 while 迴圈
      {
        sum=n/3; // 3 瓶換 1 瓶，sum 存可以換到瓶子數的值
        cola+=sum; // 將可以換到的瓶子數加進去 cola
        n=n%3+sum; // n%3 為 3 瓶換 1 瓶以外的瓶子數，再將 n%3 加上 sum ，assign 給 n ， n 為換完之後“換得的”和“剩下的”瓶數
      }
      if(n==2)
        cola++; // 如果 n 等於 2 代表可以借一個空瓶換一瓶，喝完再還回去，所以 cola 可以加 1
      cout<<cola<<endl;
    }
  }
}
