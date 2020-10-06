//uva10583
#include <bits/stdc++.h>
using namespace std;

#define MXN 50005
int N, M;
vector<int> G[MXN];
bool vis[MXN];

void dfs(int u)
{
    vis[u] = 1;
    for( int v : G[u] )
    {
        if( !vis[v] )
        {
            dfs(v);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);

    int tc = 0;
    while(cin>>N>>M && (N||M))
    {
        tc++;
        for( int i = 1; i <= N; i++ )
        {
            vis[i] = 0;
            G[i].clear();
        }
        int u, v;
        for( int i = 1; i <= M; i++ )
        {
            cin>>u>>v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        int C = 0;
        for( int i = 1; i <= N; i++ )
        {
            if( !vis[i] )
            {
                C++;
                dfs(i);
            }
        }
        cout<<"Case "<<tc<<": "<<C<<'\n';
    }

    return 0;
}