https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=997

#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
 int num;
 cin >> num;
 for (int i = 0; i < num; i++) {
  int player_num, player_n;
  double prob;
  cin >> player_num >> prob >> player_n;
  double q = 1 - prob;
  double second = pow(q, player_num);
  if (second == 1) {
   cout << "0.0000" << endl;
   continue;
  }
  double ans = prob * pow(q, player_n - 1) / (1.0 - pow(q, player_num));
  cout << fixed << setprecision(4) << ans << endl;
 }

 //system("PAUSE");
 return 0;
}