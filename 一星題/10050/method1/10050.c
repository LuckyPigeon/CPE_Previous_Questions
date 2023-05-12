/*
 * Author: @1chooo
 * Title: 10050 - Hashmat the brave warrior
 * Required: Time limit: 3.000 seconds
 * Link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=996
 * Status: AC
 */

#include <stdio.h>
#include <stdlib.h>

int main() {

  long long hashmat, opponent, difference;
  
  while (scanf("%lld %lld", &hashmat, &opponent) == 2) {
      difference = abs(hashmat - opponent);
      printf("%lld\n", difference);
  }

  return 0;
}
