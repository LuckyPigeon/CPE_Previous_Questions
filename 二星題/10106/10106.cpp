https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=934

#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

string solve(int n) {
  string ans = "";
  int i;

  while(n != 1) {
    for (i = 9; i > 1; i--) {
      if (n % i == 0) {
        n /= i;
        ans = (char)(i + '0') + ans;
        break;
      }
    }
    if (i == 1) return "-1";
  }
  return ans;
}

int main() {
  int test_case, n;
  string ans;
  scanf("%d", &test_case);
  while (test_case--) {
    scanf("%d", &n);
    if (n < 10) {
      printf("%d\n", n);
      continue;
    }
    cout << solve(n) << endl;
  }

  return 0;
}
