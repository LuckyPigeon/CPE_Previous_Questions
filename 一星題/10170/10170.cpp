#include <iostream>
using namespace std;
//規則:(1.)一個組織 一次只有一個人可以訂房 (2.)早上入房 晚上退房 (3.)下一個團體要在隔天早上才能來(4.)下一個團體要比前一個團體多一個人 (5.)幾個人住幾天
//input S = 起始團體的人數 D = 第幾天
//output 輸出第D天住的團體幾人
int main()
{
 long long int S,D;                        //接收兩個值 因為很大 所以資料型態用long long int
 long long int area;                       //算第n個團體離開的那天
 while(cin >> S >> D) {                    //當有兩個輸入就一直執行
   for(int i = 0; ; i++) {
    area = (S + (S + i)) * (i + 1) / 2;    //上底加下底乘高除二 可以算出第s+i個人的團體要離開的那一天
    if(area >= D) {                        //當area>=D 表示 第D天 是在s+i個人團體的住宿期間
      cout << S + i << endl;
      break;                               //這個for迴圈並沒有放結束的條件 當得到答案時就要跳出該迴圈
    }
   }
 }
 return 0;
}
