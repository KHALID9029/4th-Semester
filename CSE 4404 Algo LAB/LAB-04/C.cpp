#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

const int N=1e5;
const int INF=1e9+10;

int parent[N];
int siz[N];

void make(int v)
{
    parent[v]=v;
    siz[v]=1;
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

    int n,e;
    cin>>n>>e;

    vector<pair<int,int>>edges;

    while(e--)
    {
        int u,v;
        cin>>u>>v;
        edges.push_back({u,v});
    }

    sort(edges.begin(),edges.end());

    for(int i=1;i<=n;i++)
    {
        make(i);
    }

    
    for(auto &edge: edges)
    {
        
        int u=edge.first;
        int v=edge.second;

        if(find(u)==find(v)) continue;
        Union(u,v);
        cout<<u<<" "<<v<<endl;
    }
}
