https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1583

#include <iostream>

using namespace std;

int main()
{
 int num, x1, y1, x2, y2;
 while (cin>>num)
 for (int i = 1; i <= num; ++i) {
  cin >> y1 >> x1 >> y2 >> x2;
  
  long long n = (x1+y1) * (x1+y1+1LL) / 2LL + y1;
  long long m = (x2+y2) * (x2+y2+1LL) / 2LL + y2;
  
  cout << "Case " << i << ": " << (m-n) <<endl;
 }
  return 0;
}