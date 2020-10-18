#include <iostream> 
#include <cstdlib> 
using namespace std; 
int main()
{
  long long int Hashmat, opponent; // 宣告兩個長整數 Hashmat、opponent。因為資料的大小有可能超過 2^32，所以要用 long long int 存取。
  /* 用 while 迴圈讓使用者連續輸入 */
  while(cin>>Hashmat>>opponent)
  {
    cout<<abs(Hashmat-opponent)<<endl; // 數出 Hashmat 和 opponent 差的絕對值
  }
}


