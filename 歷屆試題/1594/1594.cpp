//uva1594
#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int main() {
	int n, s[20], t;
	int i, j, temp, k;

	cin >> n;
	while(n--) {
		 cin >> t;
		 for (i = 0; i < t; i++)
            cin >> s[i];
		 for (i = 0; i < 1000; i++) {
		 	for (j = 0, temp = s[0]; j < t-1 ; j++)
		 		s[j] = abs(s[j] - s[j+1]);

            s[j] = abs(s[j] - temp);
		 }
		 for (i = 0, k = 0; i < t; i++){
		 	if (s[i] != 0){
		 		k = 1;
		 		break;
			 }
		 }
		 if (k == 0) cout << "ZERO" << endl;
		 else cout << "LOOP" << endl;
	}
	return 0;
}