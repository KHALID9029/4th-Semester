#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

const int N=1e5;
const int INF=1e9+10;

void top_sort(vector<ll> adj[],vector<ll> &indegree,ll n)
{
    queue<ll> q;
    vector<ll> ans;
    for(ll i=0;i<n;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }
    while(!q.empty())
    {
        ll u=q.front();
        q.pop();
        //cout<<u<<" ";
        ans.push_back(u);
        for(auto it:adj[u])
        {
            indegree[it]--;
            if(indegree[it]==0)
            {
                q.push(it);
            }
        }
    }

    if(ans.size()!=n)
    {
        cout<<"Cycle is present"<<endl;
        return;
    }
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
}

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll v,e;
    cin>>v>>e;
    vector<ll> adj[v];
    vector<ll> indegree(v,0);
    for(ll i=0;i<e;i++)
    {
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        indegree[v]++;
    }

}