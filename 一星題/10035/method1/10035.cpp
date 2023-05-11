/*
 * Author: @1chooo
 * Title: 10035 - Primary Arithmetic
 * Required: Time limit: 3.000 seconds
 * Link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=12&page=show_problem&problem=976
 * Status: AC
 */

#include <iostream>
#include <cstdlib>

using namespace std;

int main() {

  unsigned long long int num1, num2;
  int carry;
  int carryCount;

  while (cin >> num1 >> num2) {

    if (num1 == 0 && num2 == 0)
      break;

    carry = 0;
    carryCount = 0;

    while (num1 > 0 || num2 > 0) {

      if ((num1 % 10 + num2 % 10 + carry) >= 10) {
        carry = 1;
        carryCount++;
      } else {
        carry = 0;
      }
        num1 /= 10;
        num2 /= 10;
    }

    if (carryCount == 0)
      cout << "No carry operation." << endl;
    else if (carryCount > 1)
      cout << carryCount << " carry operations." << endl;
    else
      cout << "1 carry operation." << endl;
  }
  return 0;
}