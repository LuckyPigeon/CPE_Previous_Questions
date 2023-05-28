// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=431

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
  char s[105][105];
  int i = 0, j, k, maxlen = 0, l[105];
  while (gets(s[i]))
  {                      // 一次讀進一行字串
    l[i] = strlen(s[i]); // 儲存每行字數
    if (strlen(s[i]) > maxlen)
      maxlen = strlen(s[i]); // 更新最長字串
    i++;
  }
  for (j = 0; j < maxlen; j++)
  { // j 為第幾個字
    for (k = 0; k < i; k++)
    { // i 為行數
      if (j < l[i - 1 - k])
        cout << s[i - 1 - k][j]; // 從最後一行的字開始印( i - 1 行是最後一行)
      else
        cout << " "; // 如果這行沒有第 j 個字，就印空格
    }
    cout << endl;
  }
  return 0;
}
