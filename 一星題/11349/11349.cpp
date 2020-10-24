https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2324

#include<iostream>
#include<cmath>
using namespace std;
int main(){
 int n; 
 cin >> n; // 輸入共有 n 個矩陣
 for(int i = 0; i < n; i++){
  char c1, c2;
  long long m = 0, st = 0, ne = 0;
  cin >> c1 >> c2 >> m; // 輸入 N = 和矩陣大小 m
  long long matrix[m][m]; // 宣告 m*m 的矩陣
  for(int j = 0; j < m; j++)
   for(int k = 0; k < m; k++){
    cin >> matrix[j][k]; // 輸入矩陣裡的元素
    if(matrix[j][k] < 0) // 如果質為負的,則 ne 加 1
     ne++;
   }
  for(int j = 0; j < m; j++)
   for(int k = 0; k < m; k++) // 比較矩陣裡對角的元素是否相同
    if(matrix[j][k] != matrix[abs(m - 1 -j)][abs(m - 1 - k)]) // 如果不相同,則 st 加 1
     st++;
  if(st > 1 || ne > 0) // 如果 st 大於 1 ,(不對稱的個數大於 1 ),或是 ne 大於 0 ,(負的元素大於 0 ),則 Non-symmetric
   cout << "Test #" << i + 1 << ": Non-symmetric." << endl;
  else // 否則 Symmetric
   cout << "Test #" << i + 1 << ": Symmetric." << endl;
 }
 return 0;
}
