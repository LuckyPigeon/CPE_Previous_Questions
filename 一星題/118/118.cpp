#include <iostream> // 
#include <string>
#include <stdio.h>
using namespace std;

// 功能： 把字元 dire 轉換成數字（N = 0, E = 1, S = 2, W = 3）
// 輸入： 需傳入 dire 字元
// 回傳值： 整數型態
int direction(char dire)
{
  if (dire == 'N')
    return 0;
  else if (dire == 'E')
    return 1;
  else if (dire == 'S')
    return 2;
  else
    return 3;
}

// 功能： 交換 a 與 b 兩整數
// 輸入： 需傳入 a 與 b 兩個整數指標
// 回傳值： 無
int move(int &x, int &y, int d)
{
  if (d == 0)
    ++y;
  else if (d == 1)
    ++x;
  else if (d == 2)
    --y;
  else
    --x;
  return 0;
}

// 功能： 交換 a 與 b 兩整數
// 輸入： 需傳入 a 與 b 兩個整數指標
// 回傳值： 無
int fallout(int x, int y, int right, int upper)
{
  if (x == 0 || y == 0 || x > right || y > upper)
    return 1;
  else
    return 0;
}

// 功能： 交換 a 與 b 兩整數
// 輸入： 需傳入 a 與 b 兩個整數指標
// 回傳值： 無
int main()
{
  int upper, right; // upper 為上界邊界值 ， right 為右界邊界值
  int map[105][105] = {}; // 設定地圖上右最高邊界值 105
  cin >> right >> upper; // 輸入上右邊界值
  ++upper, ++right; 

  int x, y; // x 為機器人 x 座標位置，y 為機器人 y 座標位置
  while (cin >> x)
  {
    char dire; // dire 為機器人一開始面向方向 （N,S,E,W）
    string op; // op 為機器人接下來的行動 （L,R,F）
    int lost = 0; // lost 為判斷機器人是否出界

    cin >> y >> dire; // 輸入機器人 y 座標位置，機器人一開始面向方向
    cin >> op; // 輸入器人接下來的行動
    int d = direction(dire); // d 為紀錄機器人目前面向的方向 （N = 0, E = 1, S = 2, W = 3）
    ++x, ++y;

    for (int i = 0; i < op.length(); i++)
    {
      if (op[i] == 'R')
        d = (d + 1) % 4;
      else if (op[i] == 'L')
        d = (d + 3) % 4;
      else
      {
        int tx = x, ty = y;
        move(tx, ty, d);
        if (fallout(tx, ty, right, upper))
        {
          if (!map[tx][ty])
          {
            lost = 1;
            map[tx][ty] = 1;
            if (x == 1 && y == 1)
              map[0][1] = map[1][0] = 1;
            else if (x == 1 && y == upper)
              map[0][upper] = map[1][upper + 1] = 1;
            else if (x == right && y == 1)
              map[right + 1][1] = map[right][0] = 1;
            else if (x == right && y == upper)
              map[right + 1][upper] = map[right][upper + 1] = 1;
            break;
          }
        }
        else
          move(x, y, d);
      }
    }
    char di[] = "NESW";

    cout << x - 1 << " " << y - 1 << " " << di[d];
    if (lost)
      cout << " LOST";

    cout << endl;
  }
  return 0;
}
