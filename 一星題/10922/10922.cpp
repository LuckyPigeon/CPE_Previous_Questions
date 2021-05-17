https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1863

#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;    //宣告一個字串 s
    while (cin >> s)    //當有字串輸入執行while
    {
        int N = 0, count = 0;   //宣告兩個變數分別為 N , count 都給值為 0
        for (int i = 0; i < s.length(); i++)    //透過減 ' 0 ' 的 ascii code 得到字元的 integer 值，存到N
        {
            N += (int)s[i] - '0';
        }
        if (N == 0)     //如果 N 等於零 ， break 跳出迴圈
        {
            break;
        }
        cout << s << " ";
        while (N % 9 == 0)      //判斷是否是 9 的倍數 
        {
            if (N == 9)     //如果 N 等於 9 (代表最後一層)， count 加一， break 跳出迴圈
            {
                count++;
                break;
            }

            /*
                以下用來計算下一層，各位相加存到 N
            */

            int n1 = N / 1000;   
            int n2 = (N - n1 * 1000) / 100;
            int n3 = (N - n1 * 1000 - n2 * 100) / 10;
            int n4 = (N - n1 * 1000 - n2 * 100 - n3 * 10);
            N = n1 + n2 + n3 + n4;
            count++;
        }

        /*
                輸出，是 9 的倍數輸出 if 判斷式，不是 9 的倍數輸出 else 
        */

        if (N % 9 == 0)
        {
            cout << "is a multiple of 9 and has 9-degree " << count << "." << endl;
        }
        else
        {
            cout << "is not a multiple of 9." << endl;
        }
    }
}
