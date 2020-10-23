https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2456
#include <iostream>
using namespace std;
int main()
{
   int num[350]={}; // 宣告一個 int 陣列 num ，並設空的初始
   int num1,num2; // 宣告兩個 int 變數 num1 num2
   for(int i=0;i<350;i++)  //  此 for 迴圈用來存 0 到 349 的平方到 num 陣列
   {
      num[i]=i*i;
   }
   while(cin>>num1>>num2) // 當輸入 num1 num2 時，執行 while 迴圈
   {
      int sum=0; // 宣告一個 int 變數 sum ，並設初始值 0
      if(num1==0 && num2==0) //這個 if 當輸入 num1 num2 都為 0 ， break 這個 while 迴圈
      {
         break;
      }
      for(num1;num1<=num2;num1++) // 第一層 for 迴圈，從第一個數開始進去比，到最後一個數之後退出
      {
         for(int k=0;k<350;k++) // 第二層 for 迴圈，將第一層進來的數和 num 陣列相比， 裡面 if 功能為如果比對到一樣 sum 加 1
         {
            if(num1==num[k])
            {
               sum++;
            }
         }
      }
      
      cout<<sum<<endl;
   }
}
