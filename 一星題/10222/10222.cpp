https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=14&page=show_problem&problem=1163

#include <iostream>
#include <cstring>
using namespace std;
int main()
{
 const char keyboard[] = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
 const int kblength = strlen( keyboard );
 string s;
  while(getline( cin, s ))
  {
   for( int i = 0 ; i < s.length() ; i++ )
   {
    if(s[i] == ' ')
      cout << " ";
     else
     {
      for( int j = 0 ; j < kblength ; j++ )
      {
       if( keyboard[j] == tolower(s[i]))
       {
        cout << ("%c", keyboard[j-2]);
        break;
       }
    }
    }
  }   
  cout << "\n";
  }
 return 0;
}