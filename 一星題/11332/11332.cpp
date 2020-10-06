https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2307

#include <iostream>
using namespace std;

int f(int n) {
 int sum = 0;
 while(n > 0) {
  sum += n % 10;
  n /= 10;
 }
 if(sum < 10)
  return sum;
 else
  return f(sum);
}

int main() {
 int n;
 while(cin >> n && n)
  cout << f(n) << endl;

 return 0;
}