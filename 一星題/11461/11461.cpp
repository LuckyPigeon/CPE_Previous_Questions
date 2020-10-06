https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2456
#include <iostream>
using namespace std;
int main()
{
 int num[350]={};
 int num1,num2;
 for(int i=0;i<350;i++)
 {
  num[i]=i*i;
 }
 while(cin>>num1>>num2)
 {
  int sum=0;
  if(num1==0 && num2==0)
  {
   break;
  }
  for(num1;num1<=num2;num1++)
  {
   for(int k=0;k<350;k++)
   {
    if(num1==num[k])
    {
     sum++;
    }
   }
  }
  cout<<sum<<endl;
 }
}

※查詢所有題目及解答如下※
https://jennaweng0621.pixnet.net/blog/post/403629785
※查詢其他CPE題目如下※
http://jennaweng0621.pixnet.net/blog/category/6372301