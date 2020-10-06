https://uva.onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=1045

#include <iostream>
#define SIZE 100000001
int arr[SIZE][3];
int count = -1;
using namespace std;
int gcdf(int m, int n) {
  int tmp;
  count++;
  if (n > m) {
    tmp = m;
    m = n;
    n = tmp;
  }
  arr[count][0] = m;
  if (n != 0)
    arr[count+1][1] = m/n;
  if (n == 0)
    return m;
  return gcdf(n, m%n);
}
int main() {
  int gcd, a, b;
  while (cin >> a >> b) {
    if (a == 0) {
      cout << 0 << " " << 1 << " " << b << endl;
      continue;
    } else if (b == 0) {
      cout << 0 << " " << 1 << " " << a << endl;
      continue;
    }
    count = -1;
    gcd = gcdf(a, b);
    arr[count][2] = 0;
    arr[count-1][2] = 1;
    count -= 2;
    for (; count >= 0; count--)
      arr[count][2] = arr[count+1][1]*arr[count+1][2] + arr[count+2][2];
  
    if (arr[0][2]*arr[1][0]-arr[1][2]*arr[0][0] == gcd) {
      if (arr[0][0] == a)
        cout << -arr[1][2] << " " << arr[0][2] << " " << gcd << endl;
      else
        cout << arr[0][2] << " " << -arr[1][2] << " " << gcd << endl;
    } else {
      if (arr[0][0] == b)
        cout << -arr[0][2] << " " << arr[1][2] << " " << gcd << endl;
      else
        cout << arr[1][2] << " " << -arr[0][2] << " " << gcd << endl;
    }
  }
  return 0;
}
