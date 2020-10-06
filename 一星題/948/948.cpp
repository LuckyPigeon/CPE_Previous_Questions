https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=889

#include<iostream>
using namespace std;
int main() {
 int f[40] = {0, 1};
 for(int k = 2; k < 40; k++)
  f[k] = f[k - 1] + f[k - 2];
 int n;
 cin >> n;
 while(n--) {
  int m;
  cin >> m;
  cout << m << " = ";
  bool preone = false;
  for(int k = 39; k >= 2; k--) {
   if(m >= f[k]) {
    cout << "1";
    m -= f[k];
    preone = true;
   }
   else if(preone) {
    cout << "0";
   }
  }
  cout << " (fib)" << endl;
 }
 return 0;
}
