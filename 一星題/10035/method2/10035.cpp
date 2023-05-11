/*
 * Author: @1chooo
 * Title: 10035 - Primary Arithmetic
 * Required: Time limit: 3.000 seconds
 * Link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=12&page=show_problem&problem=976
 * Status: AC
 */

#include <iostream>
#include <cstdlib>

class Solution {
 public:
  void privacyArithmetic() {
    unsigned long long int num1, num2;
    int carry, carryCount;

    while (std::cin >> num1 >> num2) {
      if (num1 == 0 && num2 == 0) break;

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
        std::cout << "No carry operation." << std::endl;
      else if (carryCount > 1)
        std::cout << carryCount << " carry operations." << std::endl;
      else
        std::cout << "1 carry operation." << std::endl;
    }
  }
};

int main() {
  Solution s;
  s.privacyArithmetic();
  return 0;
}
