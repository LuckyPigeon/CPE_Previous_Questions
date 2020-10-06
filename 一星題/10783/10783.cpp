https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1724
#include <iostream>
using namespace std;
int main()
{
 int T,a,b,time=0;
 cin>>T;
 while(T--)
 {
  cin>>a>>b;
  time++;
  int sum=0;
  for(a;a<=b;a++)
  {
   if(a%2==1)
    sum+=a;
  }
  cout<<"Case "<<time<<": "<<sum<<endl;
 }
}

※查詢所有題目及解答如下※
https://jennaweng0621.pixnet.net/blog/post/403629785
※查詢其他CPE題目如下※
http://jennaweng0621.pixnet.net/blog/category/6372301