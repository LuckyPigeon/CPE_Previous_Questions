//uva1316
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

struct item{
    int price, day;
};

bool cmp(const item& a, const item& b){
    return a.price > b.price;
}

int main(){
    int n, ans;
    int i, j, k;
    int s[10005];
    item t[10005];
    while (scanf("%d", &n) == 1){
        for(i = 0; i < n; i++){
            scanf("%d%d", &t[i].price, &t[i].day);
        }
        sort(t, t+n, cmp);
        memset(s, -1, sizeof(s));
        ans = 0;
        for(i = 0; i < n; i++){
            int v = t[i].day;
            for(;;){
                if (s[v] == -1){
                    k = v;
                    break;
                }
                else
                    v = s[v];
            }
            if(k){
                ans += t[i].price;
                s[k] = k - 1;
            }
        }
        printf("%d\n", ans);
    }

}