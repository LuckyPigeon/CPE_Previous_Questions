https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1111

#include <iostream>
using namespace std;
int main()
{
 long long int S,D;
 long long int area;
 while(cin >> S >> D) {
   for(int i = 0; ; i++) {
    area = (S + (S + i)) * (i + 1) / 2;
    if(area >= D) {
      cout << S + i << endl;
      break;
    }
   }
 }
 return 0;
}