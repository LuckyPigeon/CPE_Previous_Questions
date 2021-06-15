#include <iostream>
#include <string>

using namespace std;

int main()
{
    int T;
    cin >> T;
    string table[21];

    while(T--){
        int m, n ,q;

        cin >> m >> n >> q;
        for(int i = 0; i < m; i++){
            table[i].clear();
            cin >> table[i];
        }
        for(int i = 0; i < m; i++){
            cout <<  table[i] << '\n';
        }
        cout << m << ' ' << n  << ' ' << q << '\n';
        for(int i = 0; i < q; i++){
            int radius = 0;
            int x, y;
            cin >> x >> y;
            char center = table[x][y];
            while (true)
            {
                if(x - radius < 0 || x + radius >= m ||  y - radius < 0 || y + radius >= n){
                    break;
                }
                else if(table[x+radius][y-radius] != center || table[x-radius][y+radius] != center || table[x+radius][y+radius] != center ||table[x+radius][y-radius] != center){
                    break;
                }
                else if(table[x+radius][y+radius] != center || table[x-radius][y-radius] != center || table[x-radius][y+radius] != center ||table[x-radius][y-radius] != center){
                    break;
                }
                radius++;
            }

            cout << 1 + (--radius) * 2 << '\n';           
        }
    }
}
