https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1167

#include <iostream>
#include <iomanip>
#include <map>
using namespace std;
int main()
{
 int t;
 cin >> t;
 getchar();
 getchar();
 while(t--)
 {
  map<string, int> record;
  string tree;
  int n = 0;
  while(getline(cin, tree))
  {
   if(tree.compare("") == 0)
    break;
   record[tree]++;
   n++;
  }
  for(map<string, int>::iterator i = record.begin(); i != record.end(); i++)
  {
   cout << fixed << setprecision(4);
   cout << i->first << " " << i->second*100.0/n << endl;
  }
  if(t)
   puts("");
 }
  return 0;
}