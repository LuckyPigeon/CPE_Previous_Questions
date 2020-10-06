https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=14&page=show_problem&problem=1209

#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;

int main()
{
 int x, a, temp;
 while (scanf("%d",&x) != EOF) {
  getchar();
  temp = getchar();
  int sum = 0, ans = 0;
  while (temp != '\n' && temp != EOF) {
   if (temp == '-' || temp >= '0' && temp <= '9') {
    ungetc(temp, stdin);
    scanf("%d",&a);
    ans = ans * x + sum;
    sum = sum * x + a;
   }
   temp = getchar();
  }
  printf("%d\n",ans);
 }
 return 0;
}
