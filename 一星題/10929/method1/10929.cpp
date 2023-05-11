/*
 * Author: @1chooo
 * Title: 10929 - You can say 11
 * Required: Time limit: 3.000 seconds
 * Link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1870
 * Status: AC
 */

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main(void) {

  string num;

  while (cin >> num && num != "0") {
    int odd = 0, even = 0;
    int sum = 0;

    for (int i = 0; i < num.length(); i++) {
      if (i % 2 == 1)
        odd += num[i] - '0';
      else 
        even += num[i] - '0';
    }

    sum = odd - even;

    if (sum % 11 == 0)
      cout << num << " is a multiple of 11." << endl;
    else  
      cout << num << " is not a multiple of 11." << endl;
  }

  return 0;
}