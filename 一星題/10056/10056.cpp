// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=997

#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

/*
 * 題目說明
 * 一個遊戲有幾位玩家，則輪流骰骰子若成立該遊戲條件就獲勝，遊戲輪流進行
 * 當有人達到條件獲勝後遊戲就停止
 * 這題必須算出第 i 個玩家獲勝的機率
 *
 * Input:
 *      先給一個整數 S ，代表有幾筆測資
 *      每個測資有一個整數 N ，代表遊戲有幾位玩家
 *      接著是投一次骰子獲勝的機率 p
 *
 * Output:
 *      輸出每筆測資該玩家獲勝的機率（精準度到小數點後第四位)
 */

int main()
{
  int num;    // 代表測資數量
  cin >> num; // 讀取測資數
  for (int i = 0; i < num; i++)
  {                                        // 共有 num 筆測資
    int player_num, player_n;              // 代表「玩家數量」以及「第幾位玩家獲勝」
    double prob;                           // 獲勝機率
    cin >> player_num >> prob >> player_n; // 讀取「玩家數量」、「第幾位玩家獲勝」、「獲勝機率」
    double q = 1 - prob;                   // 1-(獲勝機率) = 失敗機率
    double second = pow(q, player_num);    // Second 是要用來判斷成功的機率為 0 的情況
    if (second == 1)
    { // 若 (失敗的機率)^玩家數量 = 1 ， 代表失敗機率 = 1 ，即為成功機率 = 0
      cout << "0.0000" << endl;
      continue;
    }

    double ans = prob * pow(q, player_n - 1) / (1.0 - pow(q, player_num));
    /*
     * 這題主要考數學
     * 因為若第 player_n 個玩家要獲勝，他有可能在第一輪遊戲、第二輪、第三輪...第 N 輪，都有可能獲勝
     * 因此我們需要考慮好幾輪遊戲
     *
     * 則，當 i = 1 時他獲勝的機率為 q^(player_n-1) * p (前面的人都輸的情況)
     * 另，當 i = 1 時他獲勝的機率為 q^(player_num) * q^(player_n-1) * p (第一輪全部輸，第二輪前面的人都輸的情況)
     * 則到了 i = N 時它都是有規律的
     *
     * 本題求所有機率因此用 N 逼近無限大就會是解，則我們必須把 (i=1機率) + (i=2機率) + ... (i=無限 的機率) 為解答
     * 數學式可以化簡為等比級數，公比為 q^(player_num)，化簡後就是 line 21 的公式
     */
    cout << fixed << setprecision(4) << ans << endl; // 輸出答案，並且要求輸出到小數點第四位
  }

  // system("PAUSE");
  return 0;
}
