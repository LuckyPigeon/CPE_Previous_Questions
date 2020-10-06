https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1350

#include <iostream>
#include <string>
using namespace std;
int main() {
 int m;
 while (cin >> m){
  if (m <= 0)
   break;
  int u = 1, n = 2, w = 3, e = 4, s = 5, o = 6;
  for (int i = 0; i < m; i++){
   string stg;
   int t;
   cin >> stg;
   switch (stg[0]){
    case 'n':
     t = u;
     u = s;
     s = o;
     o = n;
     n = t;
     break;
    case 's':
     t = u;
     u = n;
     n = o;
     o = s;
     s = t;
     break;
    case 'e':
     t = u;
     u = w;
     w = o;
     o = e;
     e = t;
     break;
    case 'w':
     t = u;
     u = e;
     e = o;
     o = w;
     w = t;
     break;
   }
  }
  cout << u << endl;
 }
 return 0;
}