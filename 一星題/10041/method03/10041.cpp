#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

class Solution
{
public:
  void solve()
  {
    int cases;
    cin >> cases;

    while (cases--)
    {
      int relatives;
      cin >> relatives;

      vector<int> streetNumbers(relatives);
      for (int i = 0; i < relatives; i++)
      {
        cin >> streetNumbers[i];
      }

      sort(streetNumbers.begin(), streetNumbers.end());

      int median = 0;
      if (relatives % 2 == 0)
      {
        int mid = relatives / 2;
        median = (streetNumbers[mid - 1] + streetNumbers[mid]) / 2;
      }
      else
      {
        median = streetNumbers[relatives / 2];
      }

      int totalDistance = 0;
      for (int i = 0; i < relatives; i++)
      {
        totalDistance += abs(streetNumbers[i] - median);
      }

      cout << totalDistance << endl;
    }
  }
};

int main()
{
  Solution s;
  s.solve();
  return 0;
}
