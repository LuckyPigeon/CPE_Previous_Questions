https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=983

#include <iostream>
#include <cstring>
#include <cstdio>
#define PRIME_MAX 40000
using namespace std;
void MakePrime(int Prime[], int &cnt) {
 int *table = new int [PRIME_MAX];
 int i, j, k;
 memset(table, 0, sizeof(table));
 for(i = 2; i < PRIME_MAX; ++i) {
  if(!table[i]) {
   Prime[cnt++] = i;
   for(j = 2; i * j < PRIME_MAX; ++j)
    table[i * j] = 1;
  }
 }
}
int SumDigit(int n) {
 int sum = 0;
 while(n > 0) {
  sum += (n % 10);
  n /= 10;
 }
 return sum;
}
int FactorSumDigit(int Prime[], int PrimeCnt, int n) {
 int i, k;
 int sum = 0;
 for(i = 0; i < PrimeCnt && Prime[i] < n; ++i) {
  if(!(n % Prime[i])) {
   // n = Prime[i]^k * n';
   for(k = 0; !(n % Prime[i]); ++k)
    n /= Prime[i];
   // so, SumDigit(Prime[i]) only need once.
   sum += (SumDigit(Prime[i]) * k);
  }
 }
 if(n != 1) // n is prime now.
  sum += SumDigit(n);
 return sum;
}
int IsPrime(int Prime[], int PrimeCnt, int n) {
 int flag = 1, i;
 for(i = 0; i < PrimeCnt && Prime[i] * Prime[i] <= n; ++i) {
  if(!(n % Prime[i])) {
   flag = 0;
   break;
  }
 }
 // 1 -> IsPrime, 0 -> NotPrime.
 return flag;
}
int main() {
 int *Prime = new int [PRIME_MAX];
 int PrimeCnt = 0;
 MakePrime(Prime, PrimeCnt);
 int t;
 cin >> t;
 while(t--) {
  int n;
  cin >> n;
  // answer is > n (by definition from problem).
  ++n;
  // n != prime && S(n) == FS(n) break!
  // linear search is enough.
  while(IsPrime(Prime, PrimeCnt, n) || SumDigit(n) != FactorSumDigit(Prime, PrimeCnt, n))
   ++n;
  cout << n << endl;
 }
 return 0;
}
