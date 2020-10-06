//uva12918
#include <stdio.h>
#include <stdlib.h>
int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		long long int a, b;
		scanf("%lld %lld", &a, &b);
		long long int ans;
		ans = (b + b - a - 1) * a / 2 ;
		printf("%lld\n",ans);
	}
	return 0;
}