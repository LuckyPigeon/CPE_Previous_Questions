https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1356


#include <iostream>
#include <cstring>
using namespace std;

int main() {
 
 char octave[] = "XcdefgabCDEFGAB";
 
 char finger[16][11] = {
 "0000000000", /*X*/ "0111001111", /*c*/
 "0111001110", /*d*/ "0111001100", /*e*/
 "0111001000", /*f*/ "0111000000", /*g*/
 "0110000000", /*a*/ "0100000000", /*b*/
 "0010000000", /*C*/ "1111001110", /*D*/
 "1111001100", /*E*/ "1111001000", /*F*/
 "1111000000", /*G*/ "1110000000", /*A*/
 "1100000000" /*B*/
 };
 
 int t;
 
 cin >> t;
 
 cin.ignore();
 
 while(t--) {
  
   char str[300];
   cin.getline(str, 300);
   int len = strlen(str);
   int cnt[10] = {};
   int cur = 0, next;
  
   for(int i = 0; i < len; i++) {
    for(next = 1; octave[next] != str[i]; next++);
    for(int j = 0; j < 10; j++)
      if(finger[cur][j] == '0' && finger[next][j] == '1') ++cnt[j];
    cur = next;
   }
   cout << cnt[0];
   for(int j = 1; j < 10; j++)
    cout << " " << cnt[j];
   cout << endl;
 }
 return 0;
}