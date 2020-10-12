# CONTRIBUTING.md

## Table of Contents

* [Overview](#Overview)
* [Policy, rules and guidelines](#policy-rules-and-guidelines)
* [How to contribute](#how-to-contribute)
* [Template](#template)

## Overview

## Policy, rules and guidelines

## How to contribute

* For the hacktoberfest, the best begin is for you to add some comment for each code. The format for the comment, please refer to [template](#template) section

## Template

### The format for the comment(C++)

example 僅供參考，盡量遵守 style 即可。

#### 1. 註解風格

1. 盡量使用單行註解，於程式碼後空一格，並使用 `//` 加上註解。

2. 中英文之間都需要有一個空格（英文、數字的前後都要）。

3. 因註解為中文註解，標點符號請用中文標點符號（全形）。

```cpp
int i = 10; // 宣告整數 i ，數值為 10
```

#### 2. 變數註解

簡單說明該變數用途即可。

```cpp
int score = 10; // 儲存學生整數分數供 ave() 計算全班平均分數
```

#### 3. 類別、結構體註解

宣告類別的前一行註釋該類別的功能。

並簡述其方法及成員的功能。也可視需要自行額外補充其他項。

Example:

```cpp
// 功能： Student 類別存取姓名及分數
class Student{
public:
    int score; // 學生分數
    string name; // 學生姓名
}
```

#### 4. 函式註解

需描述函式功能、輸入參數、回傳值。也可視需要自行額外補充其他項。

Example:

```cpp
// 功能： 交換 a 與 b 兩整數
// 輸入： 需傳入 a 與 b 兩個整數指標
// 回傳值： 無
void swap(int *a, int *b){
    int temp = *a; // a 值會在交換中被覆蓋，因此用 temp 暫時儲存 a 的值
    *a = *b;
    *b = temp;
}
```

#### 5. 處理過長的註解

若該行程式碼加上註解，超過 80 行（ col ），請自行斷句、換行並使用 `/* */`多行註解在該程式碼後方一行。

注意： 該註解結束後，後方需有一空行，以跟其他程式碼做區分。

Example:

```cpp
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

    scanf("%d", &n); // 在這其他程式碼前要有一空行
}
```
