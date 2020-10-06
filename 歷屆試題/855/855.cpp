//uva855
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int x[50005];
int y[50005];
int main(){
    int n;
    cin>>n;
    while(n--){
        int S,A,F;
        cin>>S>>A>>F;
        for(int i=0;i<F;i++){
            cin>>x[i]>>y[i];
        }
        sort(x,x+F);
        sort(y,y+F);
        if(F%2) cout<<"(Street: "<<x[F/2]<<", Avenue: "<<y[F/2]<<")"<<endl;
        else cout<<"(Street: "<<x[(F-1)/2]<<", Avenue: "<<y[(F-1)/2]<<")"<<endl;
    }
}