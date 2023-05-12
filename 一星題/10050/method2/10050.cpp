/*
 * Author: @1chooo
 * Title: 10050 - Hashmat the brave warrior
 * Required: Time limit: 3.000 seconds
 * Link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=996
 * Status: AC
 */

#include <iostream>
#include <cstdlib>

using namespace std;

class Solution {
public:
    void run() {
        long long int army1, army2;

        while (cin >> army1 >> army2) {
            cout << abs(army1 - army2) << endl;
        }
    }
};

int main()
{
    Solution solution;
    solution.run();
    return 0;
}
