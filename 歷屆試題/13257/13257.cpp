//uva13257
#include <bits/stdc++.h>

using namespace std;
int re[100002];


int main() {
    int cas, c[26], seq;
    bool check[26][26];
    vector<int> a[26];
    string s;

    scanf("%d", &cas);
    getchar();
    while (cas--) {
        for (int i = 0; i<26; i++)
            for (int j = 0; j<26; j++)
                check[i][j] = 0;
        getline(std::cin, s);

        if (s.length()<3) {
            printf("0\n");
            continue;
        }
        memset(c, 0, sizeof(int)*26);
        memset(re, 0, sizeof(int)*100002);
        a[ (int)(s[0]-'A') ].push_back(0);
        a[ (int)(s[1]-'A') ].push_back(1);
        for (int i = 2, j = 0; i<s.length(); i++) {
            j = (int)(s[i]-'A');
            a[j].push_back(i);
            c[j]++;
            if (c[j]==1)
                re[2]++;
        }
        for (int i = 3, j = 0; i<s.length(); i++) {
            j = (int)(s[i-1]-'A');
            c[j]--;
            re[i] = c[j]==0?re[i-1]-1:re[i-1];

        }
        seq = 0;
        for (int i = 0; i<26; i++) {
            for (int j = 0; j<26; j++) {
                if (i == j && a[i].size()>1) {
                    seq+= re[a[j][1]+1];
                }
                else if(i != j && !a[i].empty() && !a[j].empty() && a[j][a[j].size()-1]>a[i][0]) {

                    int k = 0, l = a[j].size(), temp;

                    while (k!=l) {
                        temp = k+(l-k)/2;
                        if (a[j][temp]>a[i][0])
                            l = temp;
                        else
                            k = temp+1;
                    }
                    seq+= re[a[j][k]+1];
                }
            }
        }


        printf("%d\n", seq);
        for (int i = 0; i<26; i++)
            a[i].clear();
    }
    return 0;
}