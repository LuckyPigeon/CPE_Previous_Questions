//uva11417
//uva11417
#include <iostream>
using namespace std;
int gcd(int x, int y){
	int r = 0;

    while (y != 0) {
        r = x % y;
        x = y;
        y = r;
    }

    return x;
}
int main() {
   int ans[507] = {0}, n;
   for (int i = 1; i < 507; i++) {
      ans[i] = ans[i - 1];
      for (int j = 1; j < i; j++)
        ans[i]+= gcd(i, j);
   }
   while (cin >> n) {
       if (n == 0)
          break;
       else
          cout << ans[n] << endl;
   }

   return 0;
}