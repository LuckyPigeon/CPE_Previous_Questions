https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=208
#include <iostream>
using namespace std;
int main()
{
 char s;
 int n=0;
 while(cin.get(s))
 {
  if(s=='"')
  {
   n++;
   if(n%2==1)
    cout<<"``";
   else
    cout<<"''";
  }
  else
   cout<<s;
 }
}


※查詢所有題目及解答如下※
https://jennaweng0621.pixnet.net/blog/post/403629785
※查詢其他CPE題目如下※
http://jennaweng0621.pixnet.net/blog/category/6372301