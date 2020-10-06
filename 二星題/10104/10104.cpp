https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=436

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
typedef unsigned int uint;
const uint MX = 5000, CARRY = static_cast<uint>(1e9);
class BigNum {
 uint len, *num;
 
public:
 void set(uint n) {
  if (n < CARRY) {
   len = 1;
   num = (uint *)calloc(len, sizeof(uint));
   num[0] = n;
  } else {
   len = 2;
   num = (uint *)calloc(len, sizeof(uint));
   num[0] = n % CARRY;
   num[1] = n / CARRY;
  }
 }
 
 void sum(const BigNum &l, const BigNum &s) { // l.len must >= s.len
  len = l.len;
  num = (uint *)calloc(len + 1, sizeof(uint));
  memcpy(num, l.num, len * sizeof(uint));
  
  for (int i = 0; i < s.len; i++) num[i] += s.num[i];
  for (int i = 0; i < len; i++) {
   num[i+1] += num[i] / CARRY;
   num[i] %= CARRY;
  }
  
  if (num[len] > 0) len++;
 }
 
 friend ostream &operator <<(ostream &os, const BigNum &bn);
} fib[MX+1];
ostream &operator <<(ostream &os, const BigNum &bn) {
 printf("%u", bn.num[bn.len-1]);
 for (int i = (bn.len-2); i >= 0; i--) {
  printf("%09u", bn.num[i]);
 }
 return os;
}
int main() {
 fib[0].set(0);
 fib[1].set(1);
 for (int i = 2; i <= MX; i++) fib[i].sum(fib[i-1], fib[i-2]);
 
 int x;
 while (cin >> x) {
  cout << "The Fibonacci number for " << x << " is " << fib[x] << endl;
 }
 return 0;
}