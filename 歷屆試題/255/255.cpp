//uva255
#include <bits/stdc++.h>

using namespace std;

int main() {

    int k, q, m;

    while (scanf("%d %d %d", &k, &q, &m) != EOF) {

        if (k == q)
            printf("Illegal state\n");
        else {
            if (q / 8 != m / 8 && q % 8 != m % 8)
                printf("Illegal move\n");
            else {
                if (q == m)
                    printf("Illegal move\n");
                else if ((k == 0 && m == 9) || (k == 7 && m == 14) || (k == 56 && m == 49) || (k == 63 && m == 54))
                    printf("Stop\n");
                else if (q / 8 == m / 8 && k / 8 == m / 8) {
                    if ((k - m)*(k - q) <= 0)
                        printf("Illegal move\n");
                    else if (m == k + 1 || m == k - 1)
                        printf("Move not allowed\n");
                    else
                        printf("Continue\n");
                }
                else if (q % 8 == m % 8 && k % 8 == m % 8) {
                    if ((k - m)*(k - q) <= 0)
                        printf("Illegal move\n");
                    else if (m == k + 8 || m == k - 8)
                        printf("Move not allowed\n");
                    else
                        printf("Continue\n");
                }
                else {
                    if (((m - 1) / 8 == m / 8 && m - 1 == k) || ((m + 1) / 8 == m / 8 && m + 1 == k))
                        printf("Move not allowed\n");
                    else if(((m - 8) >= 0 && k == m - 8) || ((m + 8) < 64 && k == m + 8))
                        printf("Move not allowed\n");
                    else
                        printf("Continue\n");
                }
            }
        }
    }
    return 0;
}