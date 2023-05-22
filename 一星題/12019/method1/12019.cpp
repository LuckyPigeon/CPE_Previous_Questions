/*
 * Author: @1chooo
 * Title: 12019 - Doom's Day Algorithm
 * Required: frequency limit: 1.000 seconds
 * Link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3170
 * Status: AC
 */

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(void) {

  int cases;
  int month, day;
  string weekday[7] = {
    "Monday", "Tuesday", "Wednesday",
    "Thursday", "Friday", "Saturday",
    "Sunday"
  };
  int daysOfNonLeapYear[12] = {
    31, 28, 31,
    30, 31, 30,
    31, 31, 30,
    31, 30, 31
  };

  cin >> cases;

  // 2010/12/31: Friday
  // 2022/12/31: Saturday
  while (cases--) {
    cin >> month >> day;

    int dayCount = 4;

    for (int i = 0; i < month - 1; i++)
      dayCount += daysOfNonLeapYear[i];

    dayCount = (dayCount + day) % 7;
    cout << weekday[dayCount] << endl;
  }

  return 0;
}