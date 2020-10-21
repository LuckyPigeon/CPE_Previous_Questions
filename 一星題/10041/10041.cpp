#include <iostream>
#include <vector>
#include <algorithm>
// 題目：有個人要搬家，找出他跟每個親戚最短距離的合
/*
	輸入：
		1.幾個案例
		2.有幾個親戚
		3.每個親戚分別住
*/
// 輸出：找出他跟每個人的最短距離的合
using namespace std;
vector<int> num;

int main()
{
 int n, k ,d;
 cin>>n;
 while(n--)
 {
  cin>>k;
  num.clear(); // 不同的case，每次都要清空 vector
  for(int i=0; i<k;i++)
  {
   cin>>d;
   num.push_back(d); // 用 push_back() 把值從 vector 的最後一個位置插入
  }
  sort(num.begin(), num.end()); // 由小到大排序，begin() 為第一個位置，end() 為末端的後一個位置
  int mid=num[k/2]; // 取中間值，在中間走到每個點的距離和必定是最短的
  int sum=0; // 不同的case，每次都要歸零 sum
  for(int i=0;i<k;i++)
  {
   sum+=abs(num[i]-mid); // 用 abs() 取絕對值，加總出路徑和
  }
  cout<<sum<<endl;
 }
 return 0;
}  
