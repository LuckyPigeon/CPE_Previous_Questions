// https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2307

#include <iostream>
using namespace std;

int f(int n) {
 int sum = 0; //初始化，用來計算位數總和
 while(n > 0) {  //n大於0時，代表還有其他位數，繼續執行
  sum += n % 10;  //取得最右邊那位數，加進sum
  n /= 10;  //每加一位數，n/10才能繼續取得下一位數
 }
 if(sum < 10)  //若位數總和小於10，即為結果
  return sum;
 else
  return f(sum);  //位數總和大於10，要繼續將sum這個數做位數相加
}

int main() {
 int n;
 while(cin >> n && n)   //若有輸入n時，繼續執行
  cout << f(n) << endl;  //到f(n)計算結果並輸出

 return 0;
}
