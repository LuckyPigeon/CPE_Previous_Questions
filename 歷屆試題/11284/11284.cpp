//uva11284
#include <bits/stdc++.h>
#define inf 1e9

using namespace std;

vector<int> store;
long long int a[100][100], pro[100], y, dp[15][1<<15];

int main() {
    int cas, n, m, p, p1;
    long long int temp1, temp2;

    scanf("%d", &cas);
    while (cas--) {
        scanf("%d %d", &n, &m);

        for (int i = 0; i<=n; i++) {
            for (int j = 0; j<=n; j++)
                a[i][j] = inf;
            a[i][i] = 0;
        }
        for (int i = 0, j, k; i<m; i++) {
            scanf("%d %d", &j, &k);
            scanf("%lld.%lld", &temp1, &temp2);
            a[k][j] = a[j][k] = min(temp1*100+temp2, a[j][k]);
        }

        for (int k = 0; k<=n; k++) {
            for (int i = 0; i<=n; i++) {
                for (int j = 0; j<=n; j++) {
                    if (a[i][j] > a[i][k]+a[k][j])
                        a[i][j] = a[i][k]+a[k][j];
                }
            }
        }

        scanf("%d", &p);
        p1 = p;
        memset(pro, 0, sizeof(pro[0])*(n+1));
        store.clear();

        for (int i = 0, st; i<p; i++) {
            scanf("%d", &st);
            if (pro[ st ] > 0)
                p1--;
            else
                store.push_back(st);
            scanf("%d.%d", &temp1, &temp2);
            pro[ st ]+= (temp1*100+temp2);
        }p = p1;

        for (int i = 0; i<p; i++) {
            for (int j = 0; j<(1<<p); j++)
                dp[i][j] = -inf;
        }
        y = -inf;

        for (int i = 1; i<(1<<p); i++) {
            for (int j = 0; j<p; j++) {
                if (i&(1<<j)) {
                    if ((i^(1<<j)) == 0) {
                        dp[j][i] = -2*a[0][ store[j] ]+pro[ store[j] ];
                        y = max(y, dp[j][i]);
                    }
                    else {
                        for (int k = 0; k<p; k++) {
                            if (i&(1<<k) && k!=j) {
                                dp[j][i] = max(dp[j][i], dp[k][i^(1<<j)]+a[0][ store[k] ]-a[ store[k] ][ store[j] ]+pro[ store[j] ]-a[0][ store[j] ]);
                                y = max(y, dp[j][i]);
                            }
                        }
                    }
                }
            }
        }

        if (y<=0)
            printf("Don't leave the house\n");
        else
            printf("Daniel can save $%lld.%02lld\n", y/100, y%100);
    }

    return 0;
}