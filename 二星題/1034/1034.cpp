https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2261

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <cstdio>
#define NUM 5
#define LEN 20

using namespace std;

bool isBig(map<string, int>::value_type &a, map<string, int>::value_type &b) {
 return (a.second < b.second);
}

int main() {
 int dataNum, courseNum[NUM], ans;
 map<string, int> course;
 map<string, int>::iterator max;
 char numInChar[LEN];
 string numInString;

 while(cin >> dataNum) { 
  if(dataNum == 0)
   break;

  ans = 0; 
  course.clear(); 

  for(int d = 0; d < dataNum; d++) {
   for(int i = 0; i < NUM; i++)
    cin >> courseNum[i];

   sort(courseNum, courseNum + NUM);

   sprintf(numInChar, "%d%d%d%d%d", courseNum[0], courseNum[1], courseNum[2], courseNum[3], courseNum[4]);
   numInString = numInChar;

   if(course.find(numInChar) == course.end())
    course[numInString] = 1; 
   else
    course[numInString]++;  
  }

  max = max_element(course.begin(), course.end(), isBig);

  for(map<string, int>::iterator it = course.begin(); it != course.end(); it++) {
   if((*it).second == (*max).second)
    ans += (*max).second;
  }

  cout << ans << endl;
 }

 return 0;
}