https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1034

#include <iostream>
#include <string>
using namespace std;

int main()
{
  string is1, dic="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";       // dic 對應 val 0->0, 1->1, A->10, B->11 ...
  int val[62], i, j;
  
  for(i=0; i<62; i++)
    val[i]=i;
  
  while(getline(cin, is1))
  {
    int sum=0, max=0;
    for(i=0; i<is1.length(); i++)        // 進位數絕對不會低於每一位數的大小, eg: 2進位 不會出現 '03333'，而應該出現只有 0 和 1 的組合
    {
      for(j=0; j<62; j++)
      {
        if(is1[i]==dic[j])
        {
          sum += val[j];                  // 因為題目說 N-base 的數一定會被 N-1 整除，所以我們可以把一個數按照位數分解 eg: 810(10進位) = 800 + 10 = (8 * (90 + 10)) + (9 + 1) 把 N-1 (也就是 9) 的因式剔除掉後剩下 (8 * 10) + 1 再做一次(8 * (9 + 1)) + 1 剃除因式後剩下 8 + 1 == 9，得知 n - 1 == 9
          if(val[j] > max)                // 進位數絕對不會低於每一位數的大小，所以這裡求最小可能的進位數
            max=val[j];                   // 如果當前字元大於前面字元的值時， val[j] 成為新的 max
          break;                          // 如果找到當前字元對應的值時，break 掉
        }
      }      
    }
    
    for(i=max; i<62; i++)
    {      
      if(sum==0)                          // 如果 sum == 0 的話是 2進位 ，不特殊判斷的話會變 1進位
      {
        cout<<"2"<<endl;
        break;
      }
      else if(sum%i == 0)               // 同 24行 註釋，只要知道 各個位元加起來總和 % (n - 1) == 0 時，我們就可以得知 n 為多少
      {
        cout << i+1 << endl;
        break;
      }      
    }    
    if(i==62)                           // 題目規定最高位數 62 ，超過輸出沒答案
      cout << "such number is impossible!" << endl;      
  }
  return 0;
}
