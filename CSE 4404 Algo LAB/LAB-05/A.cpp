#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

const ll N=1e5;
const ll INF=1e9+10;

ll parent[N];
ll siz[N];

void make(ll v)
{
    parent[v]=v;
    siz[v]=1;
}

ll find(ll v)
{
    if(v==parent[v]) return v;
    return parent[v]=find(parent[v]); //PATH COMPRESSION OPERATION
}

void Union(ll a,ll b)
{
    a=find(a);
    b=find(b);

    if(a!=b)
    {
        if(siz[a]<siz[b]) {swap(a,b);}
        parent[b]=a;
        siz[a]+=siz[b];
    }
}
int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,e;
    cin>>n>>e;

    vector<pair<ll, pair<ll,ll>>>edges;

    while(e--)
    {
        ll u,v,wt;
        cin>>u>>v>>wt;
        edges.push_back({wt,{u,v}});
    }

    sort(edges.begin(),edges.end());

    for(ll i=1;i<=n;i++)
    {
        make(i);
    }

    ll total_cost=0;

    for(auto &edge: edges)
    {
        int wt=edge.first;
        int u=edge.second.first;
        int v=edge.second.second;

        if(find(u)==find(v)) continue;
        Union(u,v);
        total_cost+=wt;
        //cout<<u<<" "<<v<<endl;
    }

    bool flag=1;
    for(ll i=1;i<=n;i++)
    {
        if(find(i)!=find(1))
        {
            flag=0;
            break;
        }
    }
    if(flag) cout<<total_cost<<endl;
    else cout<<"IMPOSSIBLE"<<endl;
}
