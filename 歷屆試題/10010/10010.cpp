//uva10010
#include <iostream>
#include <string>
#include <locale>
using namespace std;

int main(){
	int d[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
	int n;
	cin >> n;
	cin.ignore();
	for(int i = 0;i < n;i++){
		getchar();
		int a, b;
		cin >> a >> b;
		cin.ignore();
		char table[a][b];
		for(int j = 0;j < a;j++){
			for(int k = 0;k < b;k++)
				cin >> table[j][k];
			getchar();
		}
		int m;
		cin >> m;
		cin.ignore();
		string s[m];
		int ans[m][3] = {0};
		for(int j = 0;j < m;j++)
			getline(cin, s[j]);
		for(int j = 0;j < a;j++)
			for(int k = 0;k < b;k++)
				for(int g = 0;g < m;g++)
					if(ans[g][0] < (int)s[g].length() && tolower(s[g][0]) == tolower(table[j][k])){
						for(int h = 0;h < 8;h++){
							int step = 0;
							while((j + d[h][0] * step) >= 0 && (k + d[h][1] * step) >= 0 &&
									(j + d[h][0] * step) <= a && (k + d[h][1] * step) <= b){
								if(tolower(s[g][step]) == tolower(table[j + d[h][0] * step][k + d[h][1] * step])){
									ans[g][0]++;
									step++;
								}
								else{
									ans[g][0] = 0;
									break;
								}
								if(ans[g][0] == (int)s[g].length()){
									ans[g][1] = j + 1;
									ans[g][2] = k + 1;
									break;
								}
							}
							if(ans[g][0] == (int)s[g].length())
								break;
							else
								ans[g][0] = 0;
						}
					}
		for(int j = 0;j < m;j++)
			cout << ans[j][1] << " " << ans[j][2] << endl;
		if(i < n - 1)
			cout << endl;
	}
	return 0;
}