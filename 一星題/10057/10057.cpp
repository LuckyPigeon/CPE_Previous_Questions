https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=998

#include <algorithm>
#include <iostream>

using namespace std;

int s[1000005];

int main()
{
 int n;
 while (cin>>n)
 {
  for ( int i = 0 ; i < n ; ++ i )
   cin>>s[i];
  sort(s, s+n);
  int val = s[(n-1)>>1], count = 0;
  for ( int i = 0 ; i < n ; ++ i )
   count += (val==s[i] || s[i]==s[n>>1]);
  cout << val << " " << count << " " << (s[n>>1] - val + 1) << endl;
 }
 return 0;
}