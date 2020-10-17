https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=960
#include <iostream>
using namespace std;
int main()
{
 int N,M,X1,X2;
 cin>>N; // 輸入測資數量
 while(N--)
 {
  cin>>M; // 輸入數值
  int sum1=0,sum2=0;
  X1=M; // 把數值當作十進位
  while(X1!=0)
  {
   if(X1%2==1)
    sum1++;
   X1/=2;   
  } // 轉 2 進位，用 sum1 有幾個 1
  int b1,b2,b3,b4;
  b1=(M/1000);
  b2=((M-(b1*1000))/100);
  b3=((M-(b1*1000)-(b2*100))/10);
  b4=(M-(b1*1000)-(b2*100)-(b3*10));
  X2=((b1*4096)+(b2*256)+(b3*16)+b4); // 換成 16 進位
  while(X2!=0)
  {
   if(X2%2==1)
    sum2++;
   X2/=2;
  } // 將 16 進位轉成 2 進位，用 sum2 算有幾個 1
  cout<<sum1<<" "<<sum2<<endl;
 } //將 sum1 sum2 印出
}

