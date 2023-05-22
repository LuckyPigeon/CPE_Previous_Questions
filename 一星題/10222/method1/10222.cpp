/*
 * Author: @1chooo
 * Title: 10222 - Decode the Mad man
 * Required: frequency limit: 3.000 seconds
 * Link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=14&page=show_problem&problem=1163
 * Status: AC
 */

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>

using namespace std;

int main(void) {

  string message;
  string table;
  table = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";

  getline(cin, message);

  for (int i = 0; i < message.size(); i++) {
    if (message[i] == ' ')
      cout << " ";
    else
      cout << table[table.find(message[i]) - 2];
  }

  cout << "\n";
  
  return 0;
}