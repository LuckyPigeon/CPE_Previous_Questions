https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1167

#include <iostream>
#include <iomanip>
#include <map>
using namespace std;
int main()
{
    int t;
    cin >> t; //總共有幾次測試資料
    getchar(); //為了不抓到空格
    while (t--) //t 多少做幾次回圈
    {
        map<string, int> record; //宣告一個 key 為 string , value 為 integer 的 map 
        string tree; //宣告一個 string
        int n = 0; //宣告一個 integer
        while (getline(cin, tree)) //當有值輸入時 , 整行 get 存到 tree
        {
            if (tree.compare("") == 0) // get 到空的就 break
                break;
            record[tree]++;  //存 tree 的值為 key , value 加 1 , 為了計算每個 tree 裡的值 , 總共有幾個
            n++; //n 加 1 , 為了計算總共有幾筆資料
        }
        for (map<string, int>::iterator i = record.begin(); i != record.end(); i++) //此回圈跑 map 中共有幾對 key , value
        {
            cout << fixed << setprecision(4); //setprecision() 用法括號內為多少就取幾位 , 加上 fixed 取值為小數點後 , 這裡是取小數點後4位
            cout << i->first << " " << i->second * 100.0 / n << endl; //i->first 為 map 的 key, i->second 為 map 的 value
                                                                      //這裡為先輸出 key , 在輸出 value 佔總數多少的百分比
        }
        if (t) //如果有大於一次測試的話 , 換行用
            puts("");
    }
    return 0;
}
