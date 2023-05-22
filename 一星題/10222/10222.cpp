// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=14&page=show_problem&problem=1163

#include <iostream>
#include <cstring>
using namespace std;
int main()
{
   const char keyboard[] = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./"; // 建立比對用的字串
   const int kblength = strlen( keyboard ); // 宣告 int 變數 kblength ，存 keyboard 的長度
   string s;
   while(getline( cin, s )) // 當有輸入就執行 while 迴圈，且 getline 為整行輸入（包含空格）
   {
      for( int i = 0 ; i < s.length() ; i++ ) //執行 for 迴圈字串長度的次數，得以每個字 decode
      {
         if(s[i] == ' ') // 這個 if 做的功能是空格保留
            cout << " "; 
         else
         {
            for( int j = 0 ; j < kblength ; j++ ) 
            {
               if( keyboard[j] == tolower(s[i])) 
                  {
                     cout << ("%c", keyboard[j-2]);
                     break;
                  }
            }
            /*
            這個 for 迴圈做的功能是比對 s[i] 在 keyboard 的第幾個位置，得以找出左邊兩個按鍵的字母。
            tolower function 功能是將大寫 char 變成小寫
            */
         }
       }   
       cout << "\n";
    }
    return 0;
}
