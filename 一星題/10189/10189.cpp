https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1130

#include<iostream>
#define MAX_N 100
#define MAX_M 100
#define MINE -100
using namespace std;
int main()
{
 int n, m, field_num = 0;
  char square;
  while(cin>>n>>m)
 {
  if (n == 0 && m == 0)
   break;
   getchar();
   if( field_num ) cout<<endl;
   int field[MAX_N+5][MAX_M+5] = {0};
   for( int i = 1 ; i <= n ; i++ )
  {
     for( int j = 1 ; j <= m ; j++ )
   {
      square = getchar();
      if( square == '*' )
    {
        field[i][j] = MINE;
        for(int k=-1; k<=1; k++)
         for(int l=-1; l<=1; l++)
           field[i+k][j+l]++;
      }
     }
     getchar();
   }
   cout << "Field #" << ++field_num << ":" <<endl;
   for( int i = 1 ; i <= n ; i++ )
  {
    for( int j = 1 ; j <= m ; j++ )
      if( field[i][j] < 0 )
     cout << "*";
      else
     cout << field[i][j];
     cout << endl;
   }
  }
  return 0;
}