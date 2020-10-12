// https://uva.onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=235

#include <stdio.h>
int main()
{
    int n, l, i, k, tr[100], t, count;
    scanf("%d", &n);
    while(n--) {
        for(i = 0; i < 100; i++)
            tr[i] = 0;
        count = 0;
        scanf("%d", &l);
        for(i = 0; i < l; i++)
            scanf("%d", &tr[i]);
        for(i = 0; i < l - 1; i++)
            for(k = 0; k < l - 1; k++)
                if(tr[k]>tr[k+1])
                {
                    t = tr[k];
                    tr[k] = tr[k + 1];
                    tr[k + 1] = t;
                    count++;
                }
        printf("Optimal train swapping takes %d swaps.\n",count);
    }
    return 0;
}