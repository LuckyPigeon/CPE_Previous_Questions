https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1162

#include<stdio.h>
#include<math.h>
int main() {
 char s[10]; // 字串陣列 s 用來紀錄是 deg 或 min
 double PI, x, y, i, j; // 變數 PI 為圓周率 3.14 ，變數 x 是弧長答案，y 是弦長答案， i 是地球到衛星的距離，j 是兩個衛星之間的角度
 PI = atan(1) * 4; // 計算精確的 pi 值利用 atan(x)
 while (scanf("%lf %lf %s",&i, &j, &s) != EOF) {
  
  // 如果是 minutes 就除以 60 得出 degree
  if (s[0] == 'm')
      j /= 60;
  j = fmod(j,360); // 取360餘數，因為角度有可能超過360度
  // 如果超過 180 就被減掉360
  if(j > 180)
      j = 360 - j; 

  x = 2 * PI * (i + 6440) * (j / 360); //計算弧長答案
  y = 2 * (i + 6440) * sin(j * PI / 360); //計算弦長答案
  printf("%.6lf %.6lf\n", x, y);// 輸出弧長答案和弦長答案

 }
 return 0;
}
