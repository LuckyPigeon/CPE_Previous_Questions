#include <iostream> # Happy Hacktoberfest 2020, Happy Hacking
using namespace std;
int condition(int n, int length)
{
    if (n == 1)
    {
        return length;
    }
    else if (n % 2 == 1)
    {
        n = (n * 3) + 1;
        condition(n, ++length);
    }
    else if (n % 2 == 0)
    {
        n /= 2;
        condition(n, ++length);
    }
}
int main()
{
    int i, j;
    while (cin >> i >> j)
    {
        cout << i << " " << j << " ";
        int max = 0;
        if (i > j)
        {
            int temp = i;
            i = j;
            j = temp;
        }
        for (i; i <= j; i++)
        {
            int length = 1;
            length = condition(i, length);
            if (max < length)
            {
                max = length;
            }
        }
        cout << max << endl;
    }
}
