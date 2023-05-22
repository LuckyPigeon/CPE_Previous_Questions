// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1724

#include <iostream>

using namespace std;

int main()
{
  int T, a, b, time = 0;
  cin >> T;   // 輸入總case數
  while (T--) // 當T不為0時，繼續執行
  {
    cin >> a >> b; // 輸入a,b值
    time++;        // 每進一次while迴圈次數+1
    int sum = 0;   // 初始化sum，用來計算結果
    for (a; a <= b; a++)
    {
      if (a % 2 == 1)
        sum += a; // 當a為奇數，a加進sum
    }
    cout << "Case " << time << ": " << sum << endl; // 輸出當次case是第幾次、結果
  }
}

// “琩高┮Τ肈ヘの秆氮“
//     https :           // jennaweng0621.pixnet.net/blog/post/403629785
// “琩高ㄤCPE肈ヘ“
//                 http: // jennaweng0621.pixnet.net/blog/category/6372301
