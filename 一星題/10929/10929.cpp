// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1870
#include <iostream>
using namespace std;
int main()
{
  string s;
  while (cin >> s) // while 輸入字串 s
  {
    int Lnum = 0, Rnum = 0; // 宣告整數 Lnum 與 Rnum 來紀錄基數位與偶數位各自相加的質
    if (s == "0")           // 如果輸入 0 ,則結束程式
    {
      break;
    }
    for (int i = 0; i < s.length(); i++) // 讓 i 的質在 0 到字串長度 -1 裡
    {
      if ((i + 1) % 2 == 1) // 如果目前的位置在基數,則把該字元變成整數,並且加到 Lnum
      {
        Lnum += (int)s[i] - '0'; // 把 s[i] 轉成 ASCII 對應到的質,並且減掉 0 的 ASCII 質,以此來讓字元換成整數
      }
      else // 否則把該字元變成整數,並且加到 Rnum
      {
        Rnum += (int)s[i] - '0'; // 把 s[i] 轉成 ASCII 對應到的質,並且減掉 0 的 ASCII 質,以此來讓字元換成整數
      }
    }
    if ((Lnum - Rnum) % 11 == 0) // 如果 Lnum-Rnum 能被 11 整除,則 s 此數為 11 的倍數,且輸出 is a multiple of 11
    {
      cout << s << " is a multiple of 11." << endl;
    }
    else // 否則 s 此數不為 11 的倍數,且輸出 is not a multiple of 11
    {
      cout << s << " is not a multiple of 11." << endl;
    }
  }
}
