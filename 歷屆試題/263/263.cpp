//uva263
#include<iostream>
#include<sstream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
bool cmp(char a, char b){
    return a>b;
}
int main(){
    int n;
    set<long long> same;
    string s,s1;
    while(getline(cin,s) && s!="0"){
        same.clear();
        stringstream sti(s);
        long long int o1=0,a1 =0,b1=0;
        sti >> o1;
        cout<<"Original number was "<<o1<<endl;
       while(1){
        sort(s.begin(),s.end(),cmp);
        stringstream sti1(s);
        sti1 >> a1;
        sort(s.begin(),s.end());
        stringstream sti2(s);
        sti2 >> b1;
        cout<<a1<<" - "<<b1<<" = "<<a1-b1<<endl;
        if( same.find(a1-b1) != same.end() ){
            break;
        }
         same.insert(a1-b1);
         stringstream its;
         its << a1-b1;
         its >> s;
       }
       cout<<"Chain length "<<same.size()+1<<endl<<endl;
    }

}