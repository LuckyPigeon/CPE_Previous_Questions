https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=431

#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int main() {
  char s[105][105];
  int i = 0, j, k, maxlen = 0, l[105];
  while(gets(s[i])) {
    l[i] = strlen(s[i]);
    if(strlen(s[i]) > maxlen)
      maxlen = strlen(s[i]);
    i++;
  }
  for(j = 0; j < maxlen; j++) {
    for(k = 0; k < i; k++) {
      if(j < l[i - 1 - k])
        cout << s[i - 1 - k][j];
      else
        cout << " ";
    }
    cout << endl;
  }
  return 0;
}