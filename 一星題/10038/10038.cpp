// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=979

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	bool isJolly; // 宣告一個 bool 值測試是否為 jolly jump
	int dataNum, *data; 
	vector<int> minus; // 宣告整數形式的陣列名為 minus
  
	while(cin >> dataNum) { // 紀錄序列長度
		data = new int [dataNum]; // 初始化陣列
		minus.clear(); // 初始化陣列
		isJolly = true; // 假定一開始 is jolly 是真
		for(int d = 0; d < dataNum; d++)
			cin >> data[d]; // 將數字逐個輸入
		for(int i = 1; i < dataNum; i++)
			minus.push_back(abs(data[i] - data[i - 1])); // 計算相鄰二值的差，並將差變成絕對值。
		sort(minus.begin(), minus.end()); // 由小到大排序
  
		for(int i = 0; i < minus.size() && isJolly; i++)
			if(minus[i] != i + 1)
 				isJolly = false;
		/* 判斷是否為 Jolly jumper */
  
		if(isJolly)
			cout << "Jolly" << endl;
		else
			cout << "Not jolly" << endl;
		/* 輸出判斷結果 */
  
		delete [] data; // 釋放記憶體
	}
	
	return 0;
}
