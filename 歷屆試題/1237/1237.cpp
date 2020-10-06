//uva1237
#include <stdio.h>
#include <stdlib.h>
int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        int k, m, p, i;
        int data1[10000], data2[10000];
        char name[10000][25];
        scanf("%d", &k);
        for (i = 0; i < k; i++)
            scanf("%s %d %d", name[i], &data1[i], &data2[i]);
        scanf("%d", &m);
        while (m--) {
            scanf("%d", &p);
            int temp = 0, key;
            for(i = 0; i < k; i++) {
                if(data1[i] <= p && p <= data2[i])
                    temp++, key = i;
                if(temp > 1) break;
            }
            if (temp == 1)
                printf("%s\n",name[key]);
            else
                printf("UNDETERMINED\n");
        }
        if(n)
            printf("\n");
    }
    return 0;
}