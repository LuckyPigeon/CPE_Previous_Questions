//uva10036
#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		int m, d;
		cin >> m >> d;
		int num[m];
		for(int j = 0 ; j < m ; j++){
			cin >> num[j];
			num[j] = abs(num[j]) %d;
		}
		int f[m + 1][100] = {0};
		f[0][0] = 1;
		for(int j = 0 ; j < m; j++)
			for(int k = 0 ; k < d ; k++)
				if(f[j][k]){
					f[j + 1][(k + d + num[j]) % d] = 1;
					f[j + 1][(k + d - num[j]) % d] = 1;
				}
		cout << (f[m][0] ? "Divisible" : "Not divisible") << endl;
	}
	return 0;
}