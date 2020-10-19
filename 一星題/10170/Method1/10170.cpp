#include<iostream>
using namespace std;
/*
  規則:
   １．一個組織，一次只有一個人可以訂房
   ２．早上入房，晚上退房
   ３．下一個團體要在隔天早上才能來
   ４．下一個團體要比前一個團體多一個人
   ５．幾個人就要住幾天
*/
// input S = 起始團體的人數； D = 第幾天 
// output 輸出第 D 天住的團體幾人
int main() {
	long long int s, d; // 接收兩個值，因為很大，所以資料型態用long long int
	long long int b; // 第 D 天住的團體幾人		
	while (cin >> s >> d) { // 接收兩個輸入，一旦沒有接收到資料就會停止 while，用在不知道接收次數時很方便
		b = s; // b 一定從起始團體人數開始上升　
		while ( ( b + s)*(b - s + 1) / 2 < d ) { // 上底加下底乘高除二，可以算出第 b 個人的團體要離開的那一天
			b++; // 只要值還少於 d 那就把 b 加一，往後推一天的意思
		}
		cout << b << endl;
	}
	return 0;
}
