// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=949

#include <iostream>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <cstdio>
#define len 5000
using namespace std;
int main()
{
  int n, length, i, j, t; // 宣告 n 當測資數量，length 計算實際長度
  char msg[len];          // 宣告一個長度很大的，用來存句子
  char alp[28] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  int num[28] = {}; // 計數用
  cin >> n;         // 輸入行數
  cin.ignore();     // 換行
  for (i = 0; i < n; i++)
  {
    cin.getline(msg, len); // 逐行取得內容
    length = strlen(msg);  // 計算句子長度
    for (j = 0; j < length; j++)
      if (isalpha(msg[j]))
        num[toupper(msg[j]) - 'A']++;
  } // 判斷是否為英文字母，並把是英文字母全轉成大寫，再把那個英文字母的計數增加
  /*
  int isalpha(int c);
  目的:檢查 c 是否為字母,
  回傳值:返回非零值，如果 c 是一個字母，否則為 0

  int toupper(int c);
  目的:將 c 轉換為大寫
  返回值:該函數等效返回大寫字母 C ，如果存在這樣的值，否則 c 保持不變。
  */
  for (i = 0; i < 26; i++)
  {
    for (j = 0; j < 26; j++)
    {
      if (num[j] < num[j + 1])
      {
        t = num[j];
        num[j] = num[j + 1];
        num[j + 1] = t;
        t = alp[j];
        alp[j] = alp[j + 1];
        alp[j + 1] = t;
      }
    }
  } // 從頭開始比大小，數量越大的放越前面，再將數量位置被移動過的字母換過去同指標處
  for (j = 0; j < 26; j++)
    if (num[j])
      printf("%c %d\n", alp[j], num[j]); // 把數量大於零的英文字母及數量印出
  return 0;
}
