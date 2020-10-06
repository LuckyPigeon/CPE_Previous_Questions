https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3170


#include <iostream>
using namespace std;
int main() {
 char week[10][10] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
 int month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
 int n;
 cin >> n;
 while(n--)
 {
  int mm, dd;
  cin >> mm >> dd;
  int w = 4;
  for(int i = 1; i < mm; i++)
   w += month[i-1];
  w = (w + dd) % 7;
  cout << week[w] << endl;
 }
 return 0;
}