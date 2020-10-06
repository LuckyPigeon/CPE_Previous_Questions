https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1034

#include <iostream>
#include <string>
using namespace std;

int main()
{
  string is1, dic="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
  int val[62], i, j;
  
  for(i=0; i<62; i++)
    val[i]=i;
  
  while(getline(cin, is1))
  {
    int sum=0, max=0;
    for(i=0; i<is1.length(); i++)
    {
      for(j=0; j<62; j++)
      {
        if(is1[i]==dic[j])
        {
          sum += val[j];
          if(val[j] > max)
            max=val[j];
          break;
        }
      }      
    }
    
    for(i=max; i<62; i++)
    {      
      if(sum==0)
      {
        cout<<"2"<<endl;
        break;
      }
      else if(sum%i == 0)
      {
        cout << i+1 << endl;
        break;
      }      
    }    
    if(i==62)
      cout << "such number is impossible!" << endl;      
  }
  return 0;
}