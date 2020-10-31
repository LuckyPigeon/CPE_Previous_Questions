#include <iostream>
using namespace std;
int main()
{
 int T,a,b,time=0;
 cin>>T;
 while(T--)
 {
  cin>>a>>b; // 讀入區間
  time++; // case 數 +1
  int sum=0;
  for(a;a<=b;a++)
  {
   if(a%2==1)
    sum+=a; // 如果是奇數，就加進 sum
  }
  cout<<"Case "<<time<<": "<<sum<<endl;
 }
}
