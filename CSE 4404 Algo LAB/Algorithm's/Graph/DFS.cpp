#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

const int N=1e5;
const int INF=1e9+10;

vector<bool> vis;

void dfs(vector<int> adj[], int n, int s)
{
    vis[s]=true;
    cout<<s<<" ";
    for(int v: adj[s])
        if(!vis[v])
            dfs(adj, n, v);
}

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;
    vector<int> adj[n+1];
    vis.resize(n+1, false);
    for(int i=0; i<m; i++)
    {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(adj, n, 1);
}