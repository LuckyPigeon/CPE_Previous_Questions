// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=976

#include <iostream>
#include <fstream>
using namespace std;
int main()
{
 	long int a, b, carry; // 宣告 a ，b ，carry 為 long int 型態
 	while(cin>>a>>b) // 輸入 a，b 值
	{
		if(a==0 && b==0)
			break; // 假如輸入值 a，b 均為 0 ，就結束程式
		int count=0; // 宣告 int 型態的 count 變數，並給定起始值為 0
		carry=0;  // 將 carry 值設為零
		
		while(a!=0 || b!=0)
		{
			carry = a%10 + b%10 +carry;
   			carry/=10;
   			a/=10;
   			b/=10;
   			if (carry!=0)
    			count++;
  		}
		// 從個位開始加，假如大於十，進位數就加一，然後往十位、百位等計算，計算到某一位數為零時，就停止
		
  	if (count==0)
   		cout << "No carry operation." << endl;
  	else if (count==1)
   		cout << "1 carry operation." << endl;
  	else
   		cout << count << " carry operations." << endl;
	// 印出進位次數
 	}
 return 0;
}


