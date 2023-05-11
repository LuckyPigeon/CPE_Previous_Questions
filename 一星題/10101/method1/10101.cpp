/*
 * Author: @1chooo
 * Title: 10101 - Bangla Numbers
 * Required: Time limit: 3.000 seconds
 * Link: https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&category=13&page=show_problem&problem=1042
 * Status: AC
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>

using namespace std;

void bangla(unsigned long long int);

int main(void) {

  unsigned long long int num;
  int cases = 1;

  while (cin >> num) {
    cout << setw(4) << cases << ".";

    if (num == 0)
      cout << " 0";
    else 
      bangla(num);

    cout << "\n";
    cases++;
  }

  return 0;
}

void bangla(unsigned long long int num) {
  if (num >= 10000000) {
    bangla(num / 10000000);
    cout << " kuti";
    num %= 10000000;
  }

  if (num >= 100000) {
    bangla(num / 100000);
    cout << " lakh";
    num %= 100000;
  }

  if (num >= 1000) {
    bangla(num / 1000);
    cout << " hajar";
    num %= 1000;
  }

  if (num >= 100) {
    bangla(num / 100);
    cout << " shata";
    num %= 100;
  }

  if (num)
    cout << " " << setw(4) << num;
}