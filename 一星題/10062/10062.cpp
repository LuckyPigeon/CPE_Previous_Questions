https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1003

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct word{
 int code, time;                           // code 代表 char 的 ASCII code，time 代表出現次數
};

// 功能: std::sort 的 compare func
// 輸入:  a 、 b，兩個要比較的 struct word
// 輸出: std::sort 的 cmp func 基本上只需要考慮回傳 < 的部分
bool cmp(struct word a, struct word b) {
 if(a.time != b.time)
  return a.time < b.time;
 else
  return a.code > b.code;
}
int main(void) {
 int i = 0, j, temp[130];                 // temp陣列 當作 counter 來計算每個 char 出現次數
 char qu[1005];                           // 輸入 大小加 5 預防超出陣列大小
 struct word ans[130];                    // 答案陣列
 while(gets(qu) != NULL) {                // 讀入整行
  if(i)                                   // uva輸出格式
   printf("\n");
  for(i = 0; i < 130; i++)
   temp[i] = 0;                           // 初始化陣列
  for(i = 0; i < strlen(qu); i++)
   temp[(int)qu[i]]++;
  
  for(i = 32, j = 0; i < 128; i++) {
   if(temp[i]) {                         // 如果出現次數不為 0 ，就把 temp 寫到 ans 內，準備 sorting
    ans[j].code = i;
    ans[j].time = temp[i];
    j++;                                // j 計算總共有幾個 char 出現超過一次
   }
  }
  sort(ans, ans + j, cmp);              // 按照 cmp func 規定的先照出現次數由小排到大，如果相同的話再照 ASCII code 由大排到小
  for(i = 0; i < j; i++)
   printf("%d %d\n", ans[i].code, ans[i].time);
  i = 1;                               // uva 輸出格式( wa -> wa -> wa )，避免輸出多一行空白
 }
 return 0;
}
