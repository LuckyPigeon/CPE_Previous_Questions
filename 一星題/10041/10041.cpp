https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=982

#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;
vector<int> num;

int main()
{
 int n, k ,d;
 cin>>n;
 while(n--)
 {
  cin>>k;
  num.clear();
  for(int i=0; i<k;i++)
  {
   cin>>d;
   num.push_back(d);
  }
  sort(num.begin(), num.end());
  int mid=num[k/2];
  int sum=0;
  for(int i=0;i<k;i++)
  {
   sum+=abs(num[i]-mid);
  }
  cout<<sum<<endl;
 }
 return 0;
}  

※查詢所有題目及解答如下※
https://jennaweng0621.pixnet.net/blog/post/403629785-CPE%E9%A1%8C%E7%9B%AE%E7%9B%AE%E9%8C%84%E5%8F%8A%E8%A7%A3%E7%AD%94
※查詢其他CPE題目如下※
http://jennaweng0621.pixnet.net/blog/category/6372301