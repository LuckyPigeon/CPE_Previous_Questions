//uva846
#include <iostream>
#include <cstdlib>
using namespace std;

int main() {

	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		long long a, b;
		cin >> a >> b;
		long long diff = b - a, j;
		if(diff >= 0 && diff <= 3)
			cout << diff << endl;
		else {
			for(j = 2; diff > 0; j += 2){
				if ((diff - j) < 0)
					break;
				else
					diff -= j;
			}
			if (diff == 0)
				cout << j - 2 << endl;
			else if (diff <= j / 2)
				cout << j - 1 << endl;
			else
				cout << j << endl;
		}
	}
	return 0;
}