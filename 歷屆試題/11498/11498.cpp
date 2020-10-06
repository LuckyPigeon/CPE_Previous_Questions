//uva11498
#include <bits/stdc++.h>

using namespace std;

int main() {
    int cas, n, m, x, y;

    while (scanf("%d", &cas) && cas) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i<cas; i++) {
            scanf("%d %d", &x, &y);
            if (x == n || y == m)
                printf("divisa\n");
            else if (x>n && y<m)
                printf("SE\n");
            else if (x>n && y>m)
                printf("NE\n");
            else if (x<n && y<m)
                printf("SO\n");
            else if (x<n && y>m)
                printf("NO\n");
        }
    }
    return 0;
}