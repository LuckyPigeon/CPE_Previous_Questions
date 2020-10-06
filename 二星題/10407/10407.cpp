https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=513


#include <iostream>
#include <cstring>
using namespace std;
void addnode(int x[], int y[], int &cnt, int i, int j, bool done[105][105]) {
 done[i][j] = true;
 x[cnt] = i;
 y[cnt] = j;
 ++cnt;
}
bool check(int i, int j, int n, int m, char map[105][105], bool done[105][105]) {
 if(i > -1 && j > -1 && i < n && j < m && map[i][j] == '@' && done[i][j] == false)
  return true;
 return false;
}
void bfs(int i, int j, int n, int m, char map[105][105], bool done[105][105]) {
 int head = 0, tail = 1;
 int que_x[10001] = {i}, que_y[10001] = {j};
 while(head < tail) {
  int tx = que_x[head], ty = que_y[head];
  map[tx][ty] = '*';
  if(check(tx , ty+1, n, m, map, done)) addnode(que_x, que_y, tail, tx , ty+1, done);
  if(check(tx+1, ty , n, m, map, done)) addnode(que_x, que_y, tail, tx+1, ty , done);
  if(check(tx , ty-1, n, m, map, done)) addnode(que_x, que_y, tail, tx , ty-1, done);
  if(check(tx-1, ty , n, m, map, done)) addnode(que_x, que_y, tail, tx-1, ty , done);
  if(check(tx-1, ty-1, n, m, map, done)) addnode(que_x, que_y, tail, tx-1, ty-1, done);
  if(check(tx-1, ty+1, n, m, map, done)) addnode(que_x, que_y, tail, tx-1, ty+1, done);
  if(check(tx+1, ty-1, n, m, map, done)) addnode(que_x, que_y, tail, tx+1, ty-1, done);
  if(check(tx+1, ty+1, n, m, map, done)) addnode(que_x, que_y, tail, tx+1, ty+1, done);
  head++;
 }
}
int main() {
 int n, m;
 char map[105][105];
 bool done[105][105];
 while(cin >> n >> m && n)
 {
  memset(map, 0, sizeof(map));
  memset(done, 0, sizeof(done));
  int i, j;
  for(i = 0; i <= n; i++)
   map[i][m] = '*';
  for(i = 0; i <= m; i++)
   map[n][i] = '*';
  for(i = 0; i < n; i++)
   for(j = 0; j < m; j++)
    cin >> map[i][j];
  int cnt = 0;
  for(i = 0; i < n; i++) {
   for(j = 0; j < m; j++) {
    if(map[i][j] == '@') {
     bfs(i, j, n, m, map, done);
     cnt++;
    }
   }
  }
  cout << cnt << endl;
 }
 return 0;
}