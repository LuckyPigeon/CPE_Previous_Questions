https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=949

#include <iostream>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <cstdio>
#define len 5000
using namespace std;
int main() {
 int n, length, i, j, t;
 char msg[len];
 char alp[28]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
 int num[28] = {};
 cin >> n;
 cin.ignore();
 for(i = 0; i < n ; i++) {
  cin.getline(msg, len);
  length = strlen(msg);
  for(j = 0; j < length; j++)
   if(isalpha(msg[j]))
    num[toupper(msg[j])-'A']++;
 }
 for(i = 0; i < 26; i++) {
  for(j = 0; j < 26; j++) {
   if(num[j] < num[j+1]) {
    t = num[j];
    num[j] = num[j+1];
    num[j+1] = t;
    t = alp[j];
    alp[j] = alp[j+1];
    alp[j+1] = t;
   }
  }
 }
 for(j = 0; j < 26; j++)
  if(num[j])
   printf("%c %d\n", alp[j], num[j]);
 return 0;
}