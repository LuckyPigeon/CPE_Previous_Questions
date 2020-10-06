//uva11987
#include <bits/stdc++.h>

using namespace std;
int ances[200001], num[200001], sum[200001], mapp[200001];

int update(int p) {
    if (p != ances[p])
        ances[p] = update(ances[p]);

    return ances[p];
}

int main () {
    int n, m, p, q, op, node;

    while (scanf("%d%d", &n, &m)!=EOF) {
        for (int i = 0; i<=n; i++)
            ances[i] = sum[i] = mapp[i] = i, num[i] = 1;
        node = n+1;
        while (m--) {
            scanf("%d", &op);
            if (op == 3) {
                scanf("%d", &p);
                int temp = mapp[p];
                printf("%d %d\n", num[ update(temp) ], sum[ update(temp) ]);
            }
            else {
                scanf("%d%d", &p, &q);
                int i = update(mapp[p]), j = update(mapp[q]);
                if (op == 1) {
                    if (i != j) {
                        sum[j]+= sum[i], num[j]+= num[i];
                        ances[i] = j;
                        sum[i] = num[i] = 0;
                    }
                }
                else {
                    if (i != j) {
                        mapp[p] = node++;
                        ances[ mapp[p] ] = j;
                        sum[j]+= p, num[j]++;
                        sum[i]-= p, num[i]--;
                    }
                }
            }
        }
    }
    return 0;
}