#include <iostream>
#include <cstdio>
using namespace std;
const int LIMIT = 1000000;
int reverse( int a )
{
 int b = 0;
  while( a != 0 )
 {
   b *= 10;
   b += a%10;
   a /= 10;
  }
  return b;
}
int main()
{
 bool composite[LIMIT+5] = {true, true};
  for( int i = 2; i <= LIMIT ; ++i )
 {
   if( !composite[i] )
  {
     for( int j = i+i ; j <= LIMIT ; j += i )
   {
      composite[j] = true;
     }
   }
  }
  int N;
  while( scanf("%d", &N) != EOF )
 {
   if( composite[N] )
  {
    cout << N << " is not prime." << endl;
    continue;
   }
   int reverseN = reverse(N);
   if( reverseN!=N && !composite[reverseN] )
     cout << N << " is emirp." << endl;
   else
    cout << N << " is prime." << endl;
  }
 return 0;
}