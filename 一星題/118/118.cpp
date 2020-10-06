#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

int direction(char dire)
{
  if (dire == 'N')
    return 0;
  else if (dire == 'E')
    return 1;
  else if (dire == 'S')
    return 2;
  else
    return 3;
}

int move(int &x, int &y, int d)
{
  if (d == 0)
    ++y;
  else if (d == 1)
    ++x;
  else if (d == 2)
    --y;
  else
    --x;
  return 0;
}

int fallout(int x, int y, int right, int upper)
{
  if (x == 0 || y == 0 || x > right || y > upper)
    return 1;
  else
    return 0;
}

int main()
{
  int upper, right;
  int map[105][105] = {};
  cin >> right >> upper;
  ++upper, ++right;

  int x, y;
  while (cin >> x)
  {
    char dire;
    string op;
    int lost = 0;

    cin >> y >> dire;
    cin >> op;
    int d = direction(dire);
    ++x, ++y;

    for (int i = 0; i < op.length(); i++)
    {
      if (op[i] == 'R')
        d = (d + 1) % 4;
      else if (op[i] == 'L')
        d = (d + 3) % 4;
      else
      {
        int tx = x, ty = y;
        move(tx, ty, d);
        if (fallout(tx, ty, right, upper))
        {
          if (!map[tx][ty])
          {
            lost = 1;
            map[tx][ty] = 1;
            if (x == 1 && y == 1)
              map[0][1] = map[1][0] = 1;
            else if (x == 1 && y == upper)
              map[0][upper] = map[1][upper + 1] = 1;
            else if (x == right && y == 1)
              map[right + 1][1] = map[right][0] = 1;
            else if (x == right && y == upper)
              map[right + 1][upper] = map[right][upper + 1] = 1;
            break;
          }
        }
        else
          move(x, y, d);
      }
    }
    char di[] = "NESW";

    cout << x - 1 << " " << y - 1 << " " << di[d];
    if (lost)
      cout << " LOST";

    cout << endl;
  }
  return 0;
}