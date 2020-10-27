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
 bool composite[LIMIT+5] = {true, true}; // true 代表非質數，而 0 跟 1 不是質數
  for( int i = 2; i <= LIMIT ; ++i ) // 先建表，把上限之內的數字都分辨好
 {
   if( !composite[i] ) // 若 i 是質數
  {
     for( int j = i+i ; j <= LIMIT ; j += i )
   {
      composite[j] = true; // 把 i 的倍數都設為非質數
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
   int reverseN = reverse(N); // 將輸入反轉
   if( reverseN!=N && !composite[reverseN] )
     cout << N << " is emirp." << endl;
   else
    cout << N << " is prime." << endl;
  }
 return 0;
}
