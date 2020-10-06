//uva12820
#include<iostream>
#include<cstdio>

using namespace std;

int main() {
    int n, s, t, i, j, k;
    char c;

    s = 1;
    while(scanf("%d", &n) != EOF){
    	getchar();
        t = 0;
        while(n--){
            int num[26] = {0};
            bool ans[30] = {};
            while(scanf("%c", &c) != EOF){
            	if(c == '\n')
            		break;
                num[c - 'a']++;
            }
            for(i = 0, j =0, k = 0; i < 26; i++){
                if(num[i]){
                    j++;
                    if(ans[num[i]]){
                        k = 1;
                        break;
                    }
                    ans[num[i]] = 1;
                }
            }
            if(k == 0 && j != 1)
                t++;
        }
        printf("Case %d: %d\n", s++, t);
    }
    return 0;
}