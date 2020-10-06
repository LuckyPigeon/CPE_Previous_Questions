https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=979

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
 bool isJolly;
 int dataNum, *data;
 vector<int> minus;

 while(cin >> dataNum) { // 紀錄序列長度
  // 初始化
  data = new int [dataNum];
  minus.clear();
  isJolly = true;
  // 紀錄整數序列
  for(int d = 0; d < dataNum; d++)
   cin >> data[d];
  // 計算相鄰二數之差值
  for(int i = 1; i < dataNum; i++)
   minus.push_back(abs(data[i] - data[i - 1]));
  // 排序
  sort(minus.begin(), minus.end());
  // 判斷是否為 Jolly jumper
  for(int i = 0; i < minus.size() && isJolly; i++)
   if(minus[i] != i + 1)
    isJolly = false;
  // 輸出判斷結果
  if(isJolly)
   cout << "Jolly" << endl;
  else
   cout << "Not jolly" << endl;
  // 釋放記憶體
  delete [] data;
 }

 return 0;
}