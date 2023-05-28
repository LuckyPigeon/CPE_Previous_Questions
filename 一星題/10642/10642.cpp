// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1583

#include <iostream>

using namespace std;

int main()
{
  int num, x1, y1, x2, y2; // 變數 num 總共會有幾項數據，變數 x1 y1 是 source circle 座標，變數 x2 y2 是 destination circle 座標

  while (cin >> num)
    for (int i = 1; i <= num; ++i)
    {
      cin >> y1 >> x1 >> y2 >> x2; // 輸入 x1, y1, x2, y2

      long long n = (x1 + y1) * (x1 + y1 + 1LL) / 2LL + y1; // 照著公式做，其中 1LL 和 2LL 是 long long的 1 和 2，得出 n
      long long m = (x2 + y2) * (x2 + y2 + 1LL) / 2LL + y2; // 照著公式做，其中 1LL 和 2LL 是 long long的 1 和 2，得出 m

      cout << "Case " << i << ": " << (m - n) << endl; // m - n  就是每個 Case 的解答
    }
  return 0;
}
