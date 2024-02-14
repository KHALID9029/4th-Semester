#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

const int N=1e5;
const int INF=1e9+10;

void dfs(int cur,vector<vector<int>>&adj,vector<int>&vis)
{
    vis[cur]=1;
    for(int nxt:adj[cur])
    {
        if(vis[nxt]) continue;
        cout<<cur<<" "<<nxt<<endl;
        dfs(nxt,adj,vis);
    }
}

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n+1);
    vector<int>vis(n+1);
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,adj,vis);
}