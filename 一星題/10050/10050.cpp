#include <iostream>
using namespace std;

int main() {
 int dataNum, day, political, *noWork, ans;
 bool *eachDays;

 cin >> dataNum; 
 for(int d = 0; d < dataNum; d++) {
  cin >> day >> political; 

  ans = 0;
  noWork = new int [political];
  eachDays = new bool [day];
  for(int i = 0; i < day; i++) // 先將所有日子預設為沒有罷工
   eachDays[i] = false;

  for(int i = 0; i < political; i++)
   cin >> noWork[i];

  for(int i = 0; i < political; i++)
   for(int j = noWork[i] - 1; j < day; j += noWork[i]) // 每隔 noWork[i] 天就罷工
    eachDays[j] = true;

  for(int i = 0; i < day; i++)
   if(eachDays[i] && i % 7 != 5 && i % 7 != 6) // eachDays[i] == true 就罷工，但星期五跟六不罷工
    ans++;

  delete [] noWork;
  delete [] eachDays;
  cout << ans << endl; 
 }

 return 0;
}
