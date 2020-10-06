https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1162

#include<stdio.h>
#include<math.h>
int main() {
 char s[10];
 double PI, x, y, i, j;
 PI = atan(1) * 4;
 while (scanf("%lf %lf %s",&i, &j, &s) != EOF) {
  if (s[0] == 'm')
      j /= 60;
    j = fmod(j,360); // add this line
  if(j > 180)
      j = 360 - j;

  x = 2 * PI * (i + 6440) * (j / 360);
  y = 2 * (i + 6440) * sin(j * PI / 360);
  printf("%.6lf %.6lf\n", x, y);

 }
 return 0;
}
