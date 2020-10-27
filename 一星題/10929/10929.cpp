// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1870
#include <iostream>
using namespace std;
int main()
{
 string s;
 while(cin>>s)
 {
  int Lnum=0, Rnum=0;
  if(s=="0")
  {
   break;
  }
  for(int i=0;i<s.length();i++)
  {
   if((i+1)%2==1)
   {
    Lnum+=(int)s[i]-'0'; // 將奇數位數的數字加起來
   }
   else
   {
    Rnum+=(int)s[i]-'0'; // 將偶數位數的數字加起來
   }
  }  
  if((Lnum-Rnum)%11==0) // 奇位數總和減掉偶位數總和的值若為 11 的倍數，該數便為 11 的倍數
  {
   cout<<s<<" is a multiple of 11."<<endl;
  }
  else
  {
   cout<<s<<" is not a multiple of 11."<<endl;
  }
 }
}

/*
“琩高┮Τ肈ヘの秆氮“
https://jennaweng0621.pixnet.net/blog/post/403629785-CPE%E9%A1%8C%E7%9B%AE%E7%9B%AE%E9%8C%84%E5%8F%8A%E8%A7%A3%E7%AD%94
“琩高ㄤCPE肈ヘ“
http://jennaweng0621.pixnet.net/blog/category/6372301
*/
