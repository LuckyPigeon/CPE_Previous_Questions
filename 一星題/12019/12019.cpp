// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3170

#include <iostream>  // 先引入 iostream 檔
using namespace std; // 使用 namespace std
int main()
{
  char week[10][10] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"}; // 把星期一到星期日用陣列存起來
  int month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};                                     // 把每個月的天數存起來
  int n;                                                                                              // 用變數 n 存取使用者輸入幾筆資料
  cin >> n;                                                                                           // 輸入有幾筆資料
  while (n--)
  {
    int mm, dd;                  // 用變數mm存取月份，用變數 dd 存取日期
    cin >> mm >> dd;             // 輸入月分和日期
    int w = 4;                   // 因為 2011 的一月一日式星期五，所以一開始先存取 4
    for (int i = 1; i < mm; i++) // 計算使用者所輸日的日期距離一月一日總共差幾天
      w += month[i - 1];
    w = (w + dd) % 7; // 計算使用者所輸入的日期是星期幾
    cout << week[w] << endl;
  }
  return 0;
}
