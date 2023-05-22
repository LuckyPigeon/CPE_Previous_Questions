/*
 * Author: @1chooo
 * Title: 10252 - Common Permutation
 * Required: frequency limit: 3.000 seconds
 * Link: https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=1193
 * Status: AC
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {

  string first, second;
  int countFirst, countSecond;

  while (getline(cin, first) && getline(cin, second)) {
    countFirst = 0;
    countSecond = 0;

    int letter[26] = {0};

    for (int i = 0; i < 26; i++) {
      countFirst = count(first.begin(), first.end(), 'a' + i);
      countSecond = count(second.begin(), second.end(), 'a' + i);

      letter[i] = min(countFirst, countSecond);

      if (letter[i] != 0)
        for (int j = 0; j < letter[i]; j++)
          cout << static_cast<char>('a' + i);
    }
    cout << endl;
  }

  return 0;
}