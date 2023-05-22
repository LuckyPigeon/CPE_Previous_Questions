/*
 * Author: @1chooo
 * Title: 10056 - What is the Probability ?
 * Required: frequency limit: 3.000 seconds
 * Link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=12&page=show_problem&problem=997
 * Status: AC
 */

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int main(void) {

  int set, num, serial;
  double prob, q;
  double result;
  
  cin >> set;

  while (set--) {
    cin >> num >> prob >> serial;

    if (prob == 0)
      cout << "0.0000\n";
    else {
      q = 1 - prob;
      result = pow(q, serial - 1) * prob / (1 - pow(q, num));
      printf("%.4lf\n", result);
    }
  }

  return 0;
}
