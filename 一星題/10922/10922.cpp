https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1863
#include <iostream>
#include <string>
using namespace std;
int main()
{
 string s;
 while(cin>>s)
 {
  int N=0,count=0;
  for(int i=0;i<s.length();i++)
  {
   N+=(int)s[i]-'0';
  }
  if(N==0)
  {
   break;
  }
  cout<<s<<" ";
  while(N%9==0)
  { 
   if(N==9)
   {
    count++;
    break;
   }  
   int n1=N/1000;
   int n2=(N-n1*1000)/100;
   int n3=(N-n1*1000-n2*100)/10;
   int n4=(N-n1*1000-n2*100-n3*10);
   N=n1+n2+n3+n4;
   count++;
  }
  if(N%9 == 0)
  {
   cout<<"is a multiple of 9 and has 9-degree "<<count<<"."<<endl;
  }
  else
  {
   cout<<"is not a multiple of 9."<<endl;
  }  
 }
}


※查詢所有題目及解答如下※
https://jennaweng0621.pixnet.net/blog/post/403629785
※查詢其他CPE題目如下※
http://jennaweng0621.pixnet.net/blog/category/6372301