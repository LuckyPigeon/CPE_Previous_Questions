https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1141

#include <stdio.h>
#include <string.h>
#define SIZE 10001
#define PRIMECNT 1229
int isPrime[SIZE], prime[PRIMECNT], primeCnt[SIZE];
void init();
int f(int);
int main() {
 init();
 int a, b;
 while (scanf("%d %d", &a, &b) != EOF)
  printf("%.2f\n", ((f(b) - f(a - 1)) * 100.00 / (b - (a - 1))) + 1e-9);
 return 0;
}
void init() {
 int i, j, index = 0;
 memset(isPrime, 0, sizeof(isPrime));
 for (i = 2; i < SIZE; i++) {
  if (isPrime[i] == 0) {
   prime[index++] = i;
   for (j = 2; i * j < SIZE; j++) {
    isPrime[i * j] = 1;
   }
  }
 }
  int num;
  primeCnt[0] = 1 - isPrime[41];
 for (i = 1; i < SIZE; i++) {
    num = i * i + i + 41;
    if (num < SIZE)
      primeCnt[i] = primeCnt[i - 1] + (1 - isPrime[num]);
    else {
      for (j = PRIMECNT - 1; j >= 0 && num % prime[j]; j--) ;
      if (j < 0)
        primeCnt[i] = primeCnt[i - 1] + 1;
      else
        primeCnt[i] = primeCnt[i - 1];
    }
 }
}
int f(int n) {
  return primeCnt[n];
}