#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

const int N=1e5;
const int INF=1e9+10;

int parent[N];
int size[N];

void make(int v)
{
    parent[v]=v;
    size[v]=1;
}

int find(int v)
{
    if(v==parent[v]) return v;
    return parent[v]=find(parent[v]); //PATH COMPRESSION OPERATION
}

void Union(int a,int b)
{
    a=find(a);
    b=find(b);

    if(a!=b)
    {
        if(size[a]<size[b]) {swap(a,b);}
        parent[b]=a;
        size[a]+=size[b];
    }
}
int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,e;
    cin>>n>>e;

    vector<pair<int, pair<int,int>>>edges;

    while(e--)
    {
        int u,v,wt;
        cin>>u>>v>>wt;
        edges.push_back({wt,{u,v}});
    }

    sort(edges.begin(),edges.end());

    for(int i=1;i<=n;i++)
    {
        make(i);
    }

    int total_cost=0;
    for(auto &edge: edges)
    {
        int wt=edge.first;
        int u=edge.second.first;
        int v=edge.second.second;

        if(find(u)==find(v)) continue;
        Union(u,v);
        total_cost+=wt;
        cout<<u<<" "<<v<<endl;
    }
    cout<<total_cost<<endl;
}
