#include <iostream>
using namespace std;
int condition(int n, int length)
{
    if (n == 1)                             //n == 1 結束循環
    {
        return length;                      //回傳 遞迴深度
    }
    else if (n % 2 == 1)
    {
        n = (n * 3) + 1;                    //奇數: n => 3 * n + 1
        condition(n, ++length);             //未滿足 n==1 條件繼續遞迴
    }
    else if (n % 2 == 0)
    {
        n /= 2;                             //奇數: n => n / 2
        condition(n, ++length);             //未滿足 n==1 條件繼續遞迴
    }
}
int main()
{
    int i, j;
    while (cin >> i >> j)
    {
        cout << i << " " << j << " ";       //先印出i, j避免輸出順序打亂，題目要求輸出(i j max)
        int max = 0;
        if (i > j)
        {
            int temp = i;                   //如果i(左界) > j(右界) 交換i, j 的值
            i = j;
            j = temp;
        }
        for (i; i <= j; i++)
        {
            int length = 1;
            length = condition(i, length);
            if (max < length)
            {
                max = length;               //紀錄最深遞迴長度
            }
        }
        cout << max << endl;                //印出 max(最深遞迴長度)
    }
}
