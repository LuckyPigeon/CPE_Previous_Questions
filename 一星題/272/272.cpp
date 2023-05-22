// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=208
#include <iostream>
using namespace std;
int main()
{
  char s;
  int n = 0;         // n 為計算 " 出現的次數
  while (cin.get(s)) // while 輸入 s
  {
    if (s == '\"') // 當 " 初現在輸入中,則進入 if 判斷
    {
      n++;            // n 的次數加 1
      if (n % 2 == 1) // 當 n 的次數為基數,則輸出 ``
        cout << "``";
      else // 當 n 的次數為偶數,則輸出 ''
        cout << "''";
    }
    else // 若 " 符號不輸入中,則照原本輸出
      cout << s;
  }
}
