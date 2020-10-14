#include <iostream> 
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

// 功能： 機器人開始移動，處理機器人 x,y 值
// 輸入： 需傳入 x 與 y 兩個整數 reference ， 和整式型態 d
// 回傳值： 無
int move(int &x, int &y, int d)
{
  // 如果 d 是 0 y 就加 1 
  if (d == 0)
    ++y;
  // 如果 d 是 1 x 就加 1 
  else if (d == 1)
    ++x;
  // 如果 d 是 2 y 就減 1 
  else if (d == 2)
    --y;
  // 如果 d 是 3 x 就減 1 
  else
    --x;
  return 0;
}

// 功能： 判斷機器人是否出界
// 輸入： 需傳入 x  y right upper 四個整數指標
// 回傳值： 0 或 1
int fallout(int x, int y, int right, int upper)
{
  // 如果出界就回傳 1
  if (x == 0 || y == 0 || x > right || y > upper)
    return 1;
   // 如果沒有出界就回傳 0
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
    cin >> op; // 輸入機器人接下來的行動 （L,R,F）
    int d = direction(dire); // d 為紀錄機器人目前面向的方向 （N = 0, E = 1, S = 2, W = 3）
    ++x, ++y;
    
    // 這個 for 迴圈把 op 的值一個個讀出來處理
    for (int i = 0; i < op.length(); i++)
    {
      // 如果 op[i] 值是 R
      if (op[i] == 'R')
        d = (d + 1) % 4;
      
      // 如果 op[i] 值是 L
      else if (op[i] == 'L')
        d = (d + 3) % 4;
      
      // 如果 op[i] 值是 F
      else
      {
        // 把 x y 的值分別存在 tx ty
        int tx = x, ty = y;
        
        // 把tx ty d 的值傳到函式move
        move(tx, ty, d);
        
        // 如果出界
        if (fallout(tx, ty, right, upper))
        {
          if (!map[tx][ty])
          {
            // 把 lost 傳為 1
            lost = 1;
            // 把機器人出界的前一個位子存為 1
            map[tx][ty] = 1;
            // 如果機器人是在 (1,1)出界 
            if (x == 1 && y == 1)
              map[0][1] = map[1][0] = 1;
            // 如果機器人是在 (1,upper)出界 
            else if (x == 1 && y == upper)
              map[0][upper] = map[1][upper + 1] = 1;
            // 如果機器人是在 (right,1)出界 
            else if (x == right && y == 1)
              map[right + 1][1] = map[right][0] = 1;
            // 如果機器人是在 (right,upper)出界 
            else if (x == right && y == upper)
              map[right + 1][upper] = map[right][upper + 1] = 1;
            // 離開這次迴圈
            break;
          }
        }
        // 如果沒有出界，機器人就順利移動
        else
          move(x, y, d);
      }
    }
    // 宣告字串 di ，數值為 "NESW"
    char di[] = "NESW";
    
    // 輸出機器人最後位置和面向的方向
    cout << x - 1 << " " << y - 1 << " " << di[d];
    // 如果機器人出界，就輸出" LOST"
    if (lost)
      cout << " LOST";

    cout << endl;
  }
  return 0;
}
