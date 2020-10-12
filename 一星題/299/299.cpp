// 本題其實就是考 bubble sort
#include <stdio.h>
int main()
{
    int n, l, i, k, tr[100], t, count;
    /*
        n 為測資個數、 l 為該筆測資有幾筆資料需要排序、
        i 和 k 都是給 for 迴圈使用、 
        tr 存取該測資資料供後續排序、
        t 是交換時的暫存變數、
        count 為輸出的答案，代表需交換幾次才能正確排序
    */

    scanf("%d", &n); // 讀入測資個數
    while(n--) { //重複讀入測資，共 n 筆
        for(i = 0; i < 100; i++)
            tr[i] = 0; // 歸零需要排序的資料串，避免前次結果影響
        count = 0; // 歸零交換次數（結果）
        scanf("%d", &l); // 讀入該筆測資會輸入的資料筆數（需排序的資料數量）
        for(i = 0; i < l; i++)
            scanf("%d", &tr[i]); // 讀入需要排序的資料


        // 下方二次迴圈是 bubble sort
        for(i = 0; i < l - 1; i++) // 每次都浮出一個最大值，需執行 l-1 次
            for(k = 0; k < l - 1; k++) // 每次都跟旁邊的比較大小，需執行 l-1 次
                if(tr[k]>tr[k+1]) // 若 index 大於 index+1 ，則兩者交換
                {
                    t = tr[k]; // t 是交換時暫存的變數，避免原來的 tr[k] 值消失
                    tr[k] = tr[k + 1]; // tr[k] 設為 tr[k+1] ，目前 tr[k] = tr[k+1]
                    tr[k + 1] = t; // tr[k+1] 需要設為原來的 tr[k] ，但 tr[k] 已經不是原來的 tr[k] 
                    count++; // 計數 +1 ，代表交換過一次
                }
        printf("Optimal train swapping takes %d swaps.\n",count); // 輸出結果
    }
    return 0;
}