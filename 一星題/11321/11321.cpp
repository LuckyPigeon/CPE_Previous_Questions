https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2296

#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

struct Num {
 int n,r;
 bool odd;
};

bool comp(const Num& a, const Num& b) {
 bool flag = false;
 if(a.r < b.r) flag = true;
 else if(a.r == b.r) {
  if (a.odd && !b.odd) flag = true;
  else if (!a.odd && b.odd) flag = false;
  else if (a.odd && b.odd) flag = (a.n > b.n);
  else flag = (a.n < b.n);
 }
 return flag;
}

int main() {
 int n,m,t;
 Num a[10000];
 while (cin >> n >> m && !(n == 0 && m == 0)) {
  cout << n << " " << m << endl;
  for (int i = 0; i < n; i++) {
   cin >> t;
   a[i].n = t;
   a[i].r = t%m;
   if(t%2 != 0) a[i].odd = true;
   else a[i].odd = false;
  }
  sort(a, a + n,comp);
  for (int i = 0; i < n; i++)
   cout << a[i].n << endl;
 }
 cout << "0 0" << endl;
 return 0;
}