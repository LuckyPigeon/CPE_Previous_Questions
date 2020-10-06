https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1872

#include<iostream>
#include<stack>

using namespace std;

int main() {
 stack<int> st;
 int n;
 while(cin >> n && n){
   int parity = 0;
   while(n) {
    parity += n % 2;
    st.push(n % 2);
    n /= 2;
   }
   cout << "The parity of ";
   while(st.size()) {
    cout << st.top();
    st.pop();
   }
   cout << " is " << parity << " (mod 2).\n";
 }
 return 0;
}