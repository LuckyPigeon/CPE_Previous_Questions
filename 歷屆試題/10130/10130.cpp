//uva10130
#include<bits/stdc++.h>

using namespace std;
 
int main()
{
	int T, N, G, gw, ans;
	int i, j;
	int p[1005], w[1005], eachp[35];
	
	scanf("%d", &T);
	while (T--){
		scanf("%d", &N);
		for(i = 0; i < N; i++){
			scanf("%d%d", &p[i], &w[i]);
		}
		
		memset(eachp, 0, sizeof(eachp));
		
		for(i = 0; i < N; i++){
			for(j = 30; j >= w[i]; j--){
				if(eachp[j - w[i]] + p[i] > eachp[j]){
					eachp[j] = eachp[j - w[i]] + p[i];
				}
			}
		}
		
		ans = 0;
		scanf("%d", &G);
		for(i = 0; i < G; i++){
			scanf("%d", &gw);
			ans += eachp[gw];
		}
		
		printf("%d\n", ans);
	}
	 
	return 0;
}