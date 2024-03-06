#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

const int N=1e5;
const int INF=1e9+10;

void prims(vector<pair<ll,ll>> adj[],ll n)
{
    vector<ll> key(n+1,INF);
    vector<ll> parent(n+1,-1);
    vector<bool> mst(n+1,false);
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    key[1]=0;
    pq.push({0,1});
    while(!pq.empty())
    {
        ll u=pq.top().second;
        pq.pop();
        mst[u]=true;
        for(auto it:adj[u])
        {
            ll v=it.first;
            ll w=it.second;
            if(mst[v]==false && w<key[v])
            {
                key[v]=w;
                pq.push({key[v],v});
                parent[v]=u;
            }
        }
    }
    for(ll i=2;i<=n;i++)
    {
        cout<<parent[i]<<" "<<i<<endl;
    }
}

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,m;
    cin>>n>>m;
    vector<pair<ll,ll>> adj[n+1];
    for(ll i=0;i<m;i++)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    prims(adj,n);
}