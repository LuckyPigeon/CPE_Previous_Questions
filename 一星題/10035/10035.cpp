https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=976

#include <iostream>
#include <fstream>
using namespace std;
int main()
{
 long int a, b, carry;
 
 while(cin>>a>>b)
 {
  if(a==0 && b==0)
   break;
  int count=0;
  carry=0;  
  while(a!=0 || b!=0)
  {
   carry = a%10 + b%10 +carry;
   carry/=10;
   a/=10;
   b/=10;
   if (carry!=0)
    count++;
  }
  if (count==0)
   cout << "No carry operation." << endl;
  else if (count==1)
   cout << "1 carry operation." << endl;
  else
   cout << count << " carry operations." << endl;
 }
 return 0;
}


