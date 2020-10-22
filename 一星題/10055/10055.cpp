https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=996
#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
  long long int Hashmat, opponent; // 宣告兩個 longlong int 的變數 Hashmat , opponent
  while(cin>>Hashmat>>opponent)  // 當輸入兩個變數就執行 while 迴圈
  {
    cout<<abs(Hashmat-opponent)<<endl; // 輸出 Hashmat , opponent 相減的值，做 abs function 取絕對值
  }
  return 0;
}
