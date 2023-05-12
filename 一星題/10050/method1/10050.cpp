/*
 * Author: @1chooo
 * Title: 10050 - Hashmat the brave warrior
 * Required: Time limit: 3.000 seconds
 * Link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=996
 * Status: AC
 */

#include <iostream>
#include <cstdlib>

using namespace std;

int main() {

  long long int hashmat, opponent;
  
  while(cin >> hashmat >> opponent)
    cout << abs(hashmat - opponent) << endl;
  
  return 0;
}