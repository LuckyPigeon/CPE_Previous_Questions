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

int main(void) {

  string line;
  int sum;

  while(cin >> line && line != "0") {

    if (line.length() == 1) {
      cout << line << endl;
      continue;
    }

    while (line.length() > 1) {
      sum = 0;

      for (int i = 0; i < line.length(); i++)
        sum += (int)line[i] - '0';
      
      line = to_string(sum);
    }
    cout << sum << endl;
  }

  return 0;
}