https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1131

#include <iostream>
using namespace std;

int main() {
 int n, m;
 while(cin >> n >> m) {
  if(n < 2 || m < 2) {
   cout << "Boring!\n";
   continue;
  }

  int arr[40] = {};
  int Cnt = 0;
  while(n % m == 0) {
   arr[Cnt++] = n;
   n /= m;
  }

  if(n != 1)
   cout << "Boring!\n";
  else {
   for(int i = 0; i < Cnt; ++i)
    cout << arr[i] << " ";
   cout << "1" << endl;
  }
 }
 return 0;
}