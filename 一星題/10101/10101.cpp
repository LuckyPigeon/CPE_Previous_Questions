https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1042
#include <iostream>
#include <iomanip>
using namespace std;
void kuti(long long int num)
{
 if(num>=10000000)
 {
  kuti(num/10000000);
  cout<<" kuti";
  num%=10000000;
 }
 if(num>=100000)
 {
  kuti(num/100000);
  cout<<" lakh";
  num%=100000;
 }
 if(num>=1000)
 {
  kuti(num/1000);
  cout<<" hajar";
  num%=1000;
 }
 if(num>=100)
 {
  kuti(num/100);
  cout<<" shata";
  num%=100;
 }
 if(num)
 {
  cout<<" "<<num;
 }
}
int main()
{
 long long int n;
 int time=1;
 while(cin>>n)
 {
  cout<<setw(4)<<time<<".";
  if(n==0)
  {
   cout<<" 0"<<endl;
   time++;
  }
  else
  {
   kuti(n);
   time++;
   cout<<endl;
  }
 }
}

※查詢所有題目及解答如下※
https://jennaweng0621.pixnet.net/blog/post/403629785-CPE%E9%A1%8C%E7%9B%AE%E7%9B%AE%E9%8C%84%E5%8F%8A%E8%A7%A3%E7%AD%94
※查詢其他CPE題目如下※
http://jennaweng0621.pixnet.net/blog/category/6372301