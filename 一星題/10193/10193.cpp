#include <iostream>
#include <string>
using namespace std;
//　題目：想要看兩個數值有沒有公因數
//　輸入：代表有幾個案例、一組組數值
//　輸出：只要有公因數，就輸出 pair#　（第幾個測資） All you need is love！ 沒有公因數就輸出另一個字串

int int_str(const string &s) {　//　傳入字串
	int x = 0, len = s.length();
	for (int i = 0; i < len; i++) x *= 2, x += s[i] - '0';　
   /* 
       x 乘兩倍，因為是二進位的數值 
       x 一次跟 s 拿一個數字（從第一個字開始） 後和　0　的　ascii　code　相減
       每次往後取一位都乘　2　，這樣第　n　個位置的數值就有　2　的　n　次了
   */													
 return x;　//　回傳整數
}

int gcd(int a, int b) {　//　求公因數
	while ((a %= b) && (b %= a));　//　互相取餘數，再指派餘數給它們，取到有一邊為　0　就停止
	return a + b;　//　如　a　+　b　==　1，則它們沒有公因數
}

 			    		
int main() {	
	int n;
	cin >> n;　//　接收輸入有幾個案例
	
	for (int i = 1; i <= n; i++) {　//　有　n　個案例，所以接收、判斷、輸出　n　次 
		string a, b;　//　include<string>　
		cin >> a >> b;　//　接收　n　組數對	

		cout << "Pair #" << i << ": ";　//　輸出　pair# + 第幾個案例
		if (gcd(int_str(a), int_str(b)) != 1) {　//　先傳入　int_str　轉換資料型態，再傳入　gcd（）　判斷是否有公因數 
			cout << "All you need is love!" << endl;　//　兩個數值有公因數就輸出
		}
		else {
			cout << "Love is not all you need!" << endl;　//　兩個數值沒有公因數就輸出
		}
	}
	return 0;
}
