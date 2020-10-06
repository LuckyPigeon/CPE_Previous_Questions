https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1183

#include <iostream>
#include <iomanip>

using namespace std;

typedef struct pnode
{
 double x,y;
 pnode( double a, double b ){x=a; y=b;}
 pnode(){}
}point;

int main()
{
 point a,b,c,d;
 while ( cin >> a.x >> a.y >> b.x >>b.y)
 {
  cin >> c.x >> c.y >> d.x >> d.y;
  if ( a.x==c.x && a.y==c.y )
   swap(a, b);
  if ( a.x==d.x && a.y==d.y )
  {
   swap(a, b);
   swap(c, d);
  }     
  if ( b.x==d.x && b.y==d.y )
   swap(c, d);
  point e = point((a.x + d.x - c.x), (a.y + d.y - c.y));
  
  cout << fixed;
  cout << setprecision(3);
  cout << e.x << " " << e.y << endl;
 }
 return 0;
}