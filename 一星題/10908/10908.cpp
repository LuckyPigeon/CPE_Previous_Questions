https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1849


#include <iostream>
#include <cstring>
#include <cstdio>
#define Max 101
using namespace std;
char map[Max][Max];
int LU[Max][Max], RU[Max][Max], LD[Max][Max], RD[Max][Max];
int f(int r, int c, int x, int y) {
 if(map[r][c] == map[r+x][c+y] && map[r][c] == map[r+x][c] && map[r][c] == map[r][c+y])
  return 1;
 else
  return 0;
}
void count(int m, int n) {
 int i, j;
 for(i = 0; i < m; ++i) {
  for(j = 0; j < n; ++j) {
   if(i == 0 || j == 0)
    LU[i][j] = 1;
   else
    LU[i][j] = f(i, j, -1, -1) ? min(LU[i-1][j-1], min(LU[i-1][j], LU[i][j-1])) + 1 : 1;
  }
 }
 for(i = 0; i < m; ++i) {
  for(j = n - 1; j >= 0; --j) {
   if(i == 0 || j == n - 1)
    RU[i][j] = 1;
   else
    RU[i][j] = f(i, j, -1, 1) ? min(RU[i-1][j+1], min(RU[i-1][j], RU[i][j+1])) + 1 : 1;
  }
 }
 for(i = m - 1; i >= 0; --i) {
  for(j = 0; j < n; ++j) {
   if(i == m - 1 || j == 0)
    LD[i][j] = 1;
   else
    LD[i][j] = f(i, j, 1, -1) ? min(LD[i+1][j-1], min(LD[i+1][j], LD[i][j-1])) + 1 : 1;
  }
 }
 for(i = m - 1; i >= 0; --i) {
  for(j = n - 1; j >= 0; --j) {
   if(i == m - 1 || j == n - 1)
    RD[i][j] = 1;
   else
    RD[i][j] = f(i, j, 1, 1) ? min(RD[i+1][j+1], min(RD[i+1][j], RD[i][j+1])) + 1 : 1;
  }
 }
}
int main()
{
 int t;
 cin >> t;
 while(t--)
 {
  int m, n, q, i;
  cin >> m >> n >> q;
  memset(map, 0, sizeof(map));
  memset(LU, 0, sizeof(LU));
  memset(LD, 0, sizeof(LD));
  memset(RU, 0, sizeof(RU));
  memset(RD, 0, sizeof(RD));
  for(i = 0; i < m; ++i)
   cin >> map[i];
  count(m, n);
  cout << m << " " << n << " " << q << endl;
  for(i = 0; i < q; ++i)
  {
   int r, c;
   cin >> r >> c;
   cout << min(min(LU[r][c], LD[r][c]), min(RU[r][c], RD[r][c])) * 2 - 1 << endl;
  }
 }
 return 0;
}