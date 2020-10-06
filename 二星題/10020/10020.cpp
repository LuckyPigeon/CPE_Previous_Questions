https://uva.onlinejudge.org/index.php?Itemid=8&option=com_onlinejudge&page=show_problem&problem=1047

#include<iostream>
#include<cstdio>
using namespace std;
int main() {
 string input;
 int X[255] = {0}, Y[255] = {0};
 int xlen, ylen, anslen;
 while(getline(cin, input)) {
  xlen = input.length();
  for(int i = 0; i < xlen; i++)
   X[i] = input[xlen - i - 1] - '0';
  getline(cin, input);
  ylen = input.length();
  for(int i = 0; i < ylen; i++)
   Y[i] = input[ylen - i - 1] - '0';
  int answer[510] = {0};
  for(int i = 0; i < xlen; i++) {
   for(int j = 0; j < ylen; j++) {
    answer[i + j] += X[i] * Y[j];
    answer[i + j + 1] += answer[i+j] / 10;
    answer[i + j] %= 10;
   }
  }
  anslen = xlen + ylen;
  while(anslen > 1 && !answer[anslen - 1])
   anslen--;
  for(int i = anslen-1; i >= 0; i--)
   printf("%d", answer[i]);
  printf("\n");
 }
 return 0;
}