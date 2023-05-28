/*
 * Author: @1chooo
 * Title: 11332 Summing Digits
 * Required: frequency limit: 3.000 seconds
 * Link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=25&page=show_problem&problem=2307
 * Status: AC
 */

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>

using namespace std;

int f(long long int num) {
  int sum = 0;

  while (num) {
    sum += num % 10;
    num /= 10;
  }

  if (sum > 9)
    sum = f(sum);

  return sum;
}

int main(void) {

  long long int num;

  while (cin >> num) {
    if (num == 0)
      return 0;

    cout << f(num) << "\n";
  }

  return 0;
}