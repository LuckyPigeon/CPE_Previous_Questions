https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=991

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
  for(int i = 0; i < day; i++)
   eachDays[i] = false;

  for(int i = 0; i < political; i++)
   cin >> noWork[i];

  for(int i = 0; i < political; i++)
   for(int j = noWork[i] - 1; j < day; j += noWork[i])
    eachDays[j] = true;

  for(int i = 0; i < day; i++)
   if(eachDays[i] && i % 7 != 5 && i % 7 != 6)
    ans++;

  delete [] noWork;
  delete [] eachDays;
  cout << ans << endl; 
 }

 return 0;
}