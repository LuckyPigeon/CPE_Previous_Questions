https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=14&page=show_problem&problem=1163

#include <iostream>
#include <cstring>
using namespace std;
int main()
{
 const char keyboard[] = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./"; //建立比對用的字串
 const int kblength = strlen( keyboard ); //比對用的字串的長度
 string s; //宣告一個字串
  while(getline( cin, s )) //當有整行輸入，執行 while 迴圈，並將值存入 s
  {
   for( int i = 0 ; i < s.length() ; i++ ) //將輸入一一比對，並輸出
   {
    if(s[i] == ' ') //如果為空格，一樣輸出空格
      cout << " ";
    else //如果不為空格，進行比對解碼
     {
      for( int j = 0 ; j < kblength ; j++ ) //從 s 字串第 0 格開始跟比對用的字串開始比對
      {
       if( keyboard[j] == tolower(s[i])) //如果找到一樣的輸出比對用字串前兩格的字(解碼)，tolower() function 為了解決大寫比對
       {
        cout << ("%c", keyboard[j-2]);
        break;
       }
    }
    }
  }   
  cout << "\n";
  }
 return 0;
}
