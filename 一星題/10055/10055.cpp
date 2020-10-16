#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
  
  // 輸入兩個 long long 得整數
  long long int Hashmat, opponent;// 宣告兩個長整數 Hashmat ，opponent
  // 用 while 迴圈讓使用者連續輸入 
  while(cin>>Hashmat>>opponent)
  {
    // 數出 Hashmat 和 opponent 差的絕對值
    cout<<abs(Hashmat-opponent)<<endl;
  }
}


