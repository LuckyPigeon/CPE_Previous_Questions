https://uva.onlinejudge.org/index.php?Itemid=8&category=12&option=com_onlinejudge&page=show_problem&problem=1012
#include <iostream>
using namespace std;
int main()
{
  int v,t;                                  // 物理的 v 和 t
  while(cin>>v>>t)                          // 輸入 v 和 t
  {
    if(-100<=v && v<=100 && 0<=t && t<=200)
    {
      cout<<v*2*t<<endl;                  //速度公式 H = v * t，題目說輸出 2 倍時間可以跑的距離
    }
  }
}
