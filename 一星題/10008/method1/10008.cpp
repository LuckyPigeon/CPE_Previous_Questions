/*
 * Author: @1chooo
 * Title: 10008 - What's Cryptanalysis?
 * Required: frequency limit: 3.000 seconds
 * Link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=949
 * Status: AC
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(const pair<int, char>& a, const pair<int, char>& b) {
  if (a.first == b.first)
    return a.second < b.second;
  
  return a.first > b.first;
}

int main() {

  int n;
  vector<int> frequency(26, 0);
  string s;

  cin >> n;
  cin.ignore();

  while (n--) {
    getline(cin, s);

    for (char c : s) {
      if (isalpha(c))
        frequency[toupper(c) - 'A']++;
    }
  }

  vector<pair<int, char>> frequencyList;
  for (int i = 0; i < 26; i++) {
    if (frequency[i] > 0) {
      // frequencyList.emplace_back(frequency[i], 'A' + i);
      frequencyList.push_back(make_pair(frequency[i], 'A' + i));
    }
  }

  sort(frequencyList.begin(), frequencyList.end(), cmp);

  for (auto member : frequencyList)
    printf("%c %d\n", member.second, member.first);

  return 0;
}