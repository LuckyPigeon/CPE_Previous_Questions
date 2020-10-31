// https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1361

#include<iostream>
#include<map>
using namespace std;
int main(){
 map<string,int> count;
 map<string,int>::iterator iter;
 string first_s;
 char others[76]={0};
 int n;
 cin>>n; // 總共將會有 n 行資料
 cin.ignore();
 while (n--){
   cin>>first_s; // 將國家名字讀進來
   count[first_s]++; // 將此國家的出現次數 +1
   cin.getline(others,76); // 讀掉後面不需要的資訊
 }
for (iter=count.begin(); iter!=count.end();iter++){
   cout<<iter->first<<" "; // 印出國家名
   cout<<iter->second<<endl; // 印出對應數量
 }
 return 0;
}
