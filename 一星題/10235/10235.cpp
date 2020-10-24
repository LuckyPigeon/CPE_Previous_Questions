#include <iostream>
#include <iostream>
#include <cstdio>
using namespace std;
const int LIMIT = 1000000;
int reverse( int a )
{
 int b = 0;
  while( a != 0 ) // 讓 b 存入 a 的最小位後,並且在每次存入前讓質乘以 10 ,以讓數字反轉
 {
   b *= 10;
   b += a%10;
   a /= 10;
  }
  return b;
}
int main()
{
 bool composite[LIMIT+5] = {true, true}; // 宣告 composite 陣列來紀錄是否為合數
  for( int i = 2; i <= LIMIT ; ++i )
 {
   if( !composite[i] ) // 如果 i 不是合數 , 則去尋找它的倍數,並且把它的倍數紀錄為合數
  {
     for( int j = i+i ; j <= LIMIT ; j += i )
   {
      composite[j] = true;
     }
   }
  }
  int N;
  while( scanf("%d", &N) != EOF ) // while 輸入測資 N
 {
   if( composite[N] ) // 如果 N 是合數,則輸出 is not prime
  {
    cout << N << " is not prime." << endl;
    continue;
   }
   int reverseN = reverse(N); // 反轉 N 的質,並存入 reverseN
   if( reverseN!=N && !composite[reverseN] ) // 如果反轉後的 reverseN 與反轉前的 N 不相等,並且 reverseN 為質數,則輸出 is emirp
     cout << N << " is emirp." << endl;
   else // 否則輸出 is prime
    cout << N << " is prime." << endl;
  }
 return 0;
}
