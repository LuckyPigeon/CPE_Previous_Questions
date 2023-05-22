// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1193

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
string s1 = "", s2 = "";
vector<char> same;
bool compare(char x, char y)
{
  return x + 1 < y + 1;
}
int main()
{
  while (getline(cin, s1) && getline(cin, s2))
  {
    for (size_t x = 0; x < s1.size(); x++)
    {
      for (size_t y = 0; y < s2.size(); y++)
      {
        if (s1[x] == s2[y] && s1[x] != '_')
        {
          same.push_back(s1[x]);
          s1.replace(x, 1, "_");
          s2.replace(y, 1, "_");
        }
      }
    }
    sort(same.begin(), same.end(), compare);
    for (vector<char>::iterator i = same.begin(); i != same.end(); i++)
    {
      cout << *i;
    }
    cout << endl;
    same.clear();
  }
  return 0;
}
