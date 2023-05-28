/*
 * Author: @1chooo
 * Title: 10008 - What's Cryptanalysis?
 * Required: frequency limit: 3.000 seconds
 * Link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=949
 * Status: AC
 */

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main(void) {

  int n;
  string s;
  int frequency[26] = {0};

  cin >> n;
  cin.ignore();

  while (n--) {
    getline(cin, s);

    for (int i = 0; i < s.length(); i++) {
      if (s[i] >= 'A' && s[i] <= 'Z') 
        frequency[s[i] - 'A']++;
      else if (s[i] >= 'a' && s[i] <= 'z')
        frequency[s[i] - 'a']++;
    }
  }

  int maxindex;
  for (int i = 0; i < 26; i++)
  {
    maxindex = 0;
    for (int j = 0; j < 26; j++)
    {
      if (frequency[maxindex] < frequency[j])
        maxindex = j;
    }
    if (frequency[maxindex] != 0)
    {
      printf("%c %d\n", 'A' + maxindex, frequency[maxindex]);
      frequency[maxindex] = 0;
    }
  }

  return 0;
}
