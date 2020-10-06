//uva1368
#include <bits/stdc++.h>

using namespace std;

int main() {
    int cas, m, n, err;
    int a[4][1001], temp;
    string s, s1 = {'A', 'C', 'G', 'T'};

    scanf("%d", &cas);
    while (cas--) {
        scanf("%d %d", &m, &n);
        getchar();
        memset(a, 0, sizeof(a));
        for (int i = 0; i<m; i++) {
            cin >> s;
            for (int j = 0; j<n; j++) {
                for (int k = 0; k<4; k++) {
                    if (s[j] == s1[k]) {
                        a[k][j]++;
                        break;
                    }
                }
            }
        }
        err = 0;
        for (int i = 0; i<n; i++) {
            temp = max(max(max(a[0][i], a[1][i]), a[2][i]), a[3][i]);
            err+= (m-temp);
            for (int j = 0; j<4; j++) {
                if (temp == a[j][i]) {
                    cout << s1[j];
                    break;
                }
            }
        }
        printf("\n%d\n", err);
    }
    return 0;
}