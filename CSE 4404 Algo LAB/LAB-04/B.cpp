#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

const int N=1e5;
const int INF=1e9+10;

vector<vector<int>>cc;
vector<int>current_cc;

void dfs(int cur,vector<vector<int>>&adj,vector<int>&vis)
{
    current_cc.push_back(cur);
    vis[cur]=1;
    for(int nxt:adj[cur])
    {
        if(vis[nxt]) continue;
        dfs(nxt,adj,vis);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,i;
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

    int ct=0;
    for(i=1;i<=n;i++)
    {
        if(vis[i]) continue;
        current_cc.clear();
        dfs(i,adj,vis);
        cc.push_back(current_cc);
        ct++;
    }
    

    if(ct>1)
    {
        cout<<ct-1<<"\n";
        for(i=1;i<ct;i++)
            cout<<cc[i-1][0]<<" "<<cc[i][0]<<"\n";
    }
    else cout<<0;
}
