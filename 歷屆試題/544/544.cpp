//uva544
#include <bits/stdc++.h>

using namespace std;

bool check[19900][200];

int main() {
    int n, r, num = 0;
    int k1, k2;
    int street[200][200], re[200][200], len[200];
    int route[19900][3], temp[19900][3], y;
    int city_ton[200];
    string s, s1;



    for (int ss = 1; scanf("%d%d", &n, &r) && (n || r); ss++, num = 0) {
        getchar();

        memset(len, 0, sizeof(int)*n);
        memset(city_ton, 0, sizeof(int)*n);
        for (int i = 0; i<n; i++) {
            for (int j = 0; j<n; j++)
                street[i][j] = 0;
        }
        map<string, int> city;
        for (int i = 0, l = 0; i<r; i++) {

            cin >> s, getchar(), cin >> s1, getchar(), cin >> l, getchar();

            if (city.count(s))
                k1 = city[s];
            else
                city[s] = num, k1 = num, num++;
            if (city.count(s1))
                k2 = city[s1];
            else
                city[s1] = num, k2 = num, num++;

            if (street[k1][k2]<l) {
                street[k1][k2] = l, re[k1][ len[k1] ] = k2, len[k1]++;
                street[k2][k1] = l, re[k2][ len[k2] ] = k1, len[k2]++;
            }

        }
        cin >> s, getchar(), cin >> s1, getchar();
        k1 = city[s], k2 = city[s1];

        for (int i = 0, j = 0; i<len[k1]; i++)
            j = re[k1][i], route[i][0] = j, route[i][1] = k1, route[i][2] = street[k1][j], city_ton[j] = street[k1][j];
        y = len[k1];

        y = 0;
        for (int l = 0; l<n; l++) {
            for (int i = 0; i<n; i++) {
                for (int j = 0; j<n; j++) {
                    if (street[i][j] < min(street[i][l], street[l][j]))
                        street[i][j] = min(street[i][l], street[l][j]);
                }
            }
        }
        printf("Scenario #%d\n%d tons\n\n", ss, street[k1][k2]);

    }
    return 0;
}