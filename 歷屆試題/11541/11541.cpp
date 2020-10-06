//uva11541
#include <iostream>
#include <cstdio>
using namespace std;


int main() {

    int n, total, cnt = 0;
    char alpha;

    while (cin >> n) {
        getchar();
        for(int i = 1; i <= n; i++) {
            cout << "Case " << i << ": ";
            while((alpha=getchar()) != '\n') {
                cin >> total;
                for(int i = 0; i < total; i++){
                    cout << alpha;
                }
            }
            cout << endl;
        }
    }
}