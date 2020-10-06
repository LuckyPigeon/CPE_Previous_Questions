//uva12096
#include<bits/stdc++.h>

using namespace std;

int main() {
    int cas, n;
    char op[15];

    scanf("%d", &cas);
    while (cas--) {
        scanf("%d", &n);
        getchar();

        stack< set<int> > a;
        map<set<int>, int> ma;

        int it = 0;

        for (int cass = 0; cass<n; cass++) {
            scanf("%s", &op);
            if(op[0] == 'P') {
                set<int> temp;
                a.push(temp);
            }
            else if (op[0] == 'D') {

                set<int> temp = a.top();
                a.pop(), a.push(temp), a.push(temp);
            }
            else if (op[0] == 'A') {
                set<int> temp = a.top();
                a.pop();

                if (!ma.count(temp)) {
                    a.top().insert(it), ma[temp] = it, it++;
                }
                else if ( !a.top().count(ma[temp]) )
                    a.top().insert( ma[temp] );
            }
            else if (op[0] == 'U') {
                set<int> temp = a.top();
                a.pop();
                set<int> temp1 = a.top();
                a.pop();
                set<int> temp2;

                map<set<int>, int>::iterator iter;
                for (iter = ma.begin(); iter != ma.end(); iter++) {
                    int x = iter->second;
                    if (temp.count(x) || temp1.count(x))
                        temp2.insert(x);
                }
                a.push(temp2);
            }
            else {
                set<int> temp = a.top();
                a.pop();
                set<int> temp1 = a.top();
                a.pop();
                set<int> temp2;

                map<set<int>, int>::iterator iter;
                for (iter = ma.begin(); iter != ma.end(); iter++) {
                    int x = iter->second;
                    if(temp.count(x) && temp1.count(x))
                        temp2.insert(x);
                }
                a.push(temp2);
            }
            printf("%d\n", a.top().size());
        }
        printf("***\n");
    }
    return 0;
}