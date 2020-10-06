https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=960
#include <iostream>
using namespace std;
int main()
{
 int N,M,X1,X2;
 cin>>N;
 while(N--)
 {
  cin>>M;
  int sum1=0,sum2=0;
  X1=M;
  while(X1!=0)
  {
   if(X1%2==1)
    sum1++;
   X1/=2;   
  }
  int b1,b2,b3,b4;
  b1=(M/1000);
  b2=((M-(b1*1000))/100);
  b3=((M-(b1*1000)-(b2*100))/10);
  b4=(M-(b1*1000)-(b2*100)-(b3*10));
  X2=((b1*4096)+(b2*256)+(b3*16)+b4);
  while(X2!=0)
  {
   if(X2%2==1)
    sum2++;
   X2/=2;
  }
  cout<<sum1<<" "<<sum2<<endl;
 }
}

※查詢所有題目及解答如下※
https://jennaweng0621.pixnet.net/blog/post/403629785
※查詢其他CPE題目如下※
http://jennaweng0621.pixnet.net/blog/category/6372301