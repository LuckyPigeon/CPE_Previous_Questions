//uva10268
#include <bits/stdc++.h>

using namespace std;

int main() {

    long long int x, x1, temp;
    char c;
    vector<long long int> a;

    while (scanf("%lld",&x)!=EOF) {
        while (scanf("%lld%c",&temp, &c)) {
            if (c!=' ')
                break;
            a.push_back(temp);
        }
        temp = 0, x1 = 1;
        for (int i = a.size()-1, j = 1; i>=0; i--, j++)
            temp+= a[i]*j*x1, x1*= x;
        printf("%lld\n", temp);
        a.clear();
    }
    return 0;
}