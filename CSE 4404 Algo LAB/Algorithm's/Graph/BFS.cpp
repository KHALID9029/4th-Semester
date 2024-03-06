#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

const int N=1e5;
const int INF=1e9+10;

void bfs(vector<int>adj[], int n, int s)
{
    vector<bool> vis(n+1, false);
    queue<int> q;

    vis[s]=true;
    q.push(s);

    while(!q.empty())
    {
        //cout<<"Achi\n";
        int u=q.front();
        q.pop();

        cout<<u<<" ";

        for(int v: adj[u])
            if(!vis[v])
            {
                vis[v]=true;
                q.push(v);
            }
    }
}

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;
    //cout<<n<<" "<<m<<"\n";
    vector<int> adj[n+1];
    for(int i=0; i<m; i++)
    {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(adj, n, 1);
}