#include <iostream>
using namespace std;
/*
  規則:
   １．一個組織，一次只有一個人可以訂房
   ２．早上入房，晚上退房
   ３．下一個團體要在隔天早上才能來
   ４．下一個團體要比前一個團體多一個人
   ５．幾個人住幾天
*/
//　input S = 起始團體的人數：D = 第幾天
//　output 輸出第　D　天住的團體幾人
int main()
{
 long long int S,D;　//　接收兩個值，因為很大，所以資料型態用long long int
 long long int area;　//　算第　n　個團體離開的那天
 while(cin >> S >> D) {　//　當有兩個輸入就一直執行
   for(int i = 0; ; i++) {
    area = (S + (S + i)) * (i + 1) / 2;　//　上底加下底乘高除二，可以算出第　s　+　i　個人的團體要離開的那一天
    if(area >= D) {　//　當　area　>=　D　，表示第　D　天是在　s　+　i　個人團體的住宿期間
      cout << S + i << endl;
      break;　//　這個　for　迴圈並沒有放結束的條件，當得到答案時就要跳出該迴圈
    }
   }
 }
 return 0;
}
