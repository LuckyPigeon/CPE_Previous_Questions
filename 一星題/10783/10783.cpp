// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1724
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

/*
“琩高┮Τ肈ヘの秆氮“
https://jennaweng0621.pixnet.net/blog/post/403629785
“琩高ㄤCPE肈ヘ“
http://jennaweng0621.pixnet.net/blog/category/6372301
*/
