#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
const int N=1e5+10;
const int INF=1e9+10;


void dijkstra(int source, vector<pair<int,int>>g[], vector<int>&dist, vector<int>&vis)
{
    //cout<<source<<endl;
    set<pair<int,int>>st;

    st.insert({0,source});
    dist[source]=0;

    while(st.size()>0)
    {
        auto node=*st.begin();
        int v=node.second;
        int v_dist=node.first;

        //cout<<v<<" "<<v_dist<<endl;
        st.erase(st.begin());
        if(vis[v]) continue;

        vis[v]=1;

        for(auto child:g[v])
        {
            int child_v=child.first;
            int wt=child.second;

            //cout<<child_v<<" "<<wt<<endl;

            if(dist[v]+wt <dist[child_v])
            {
                dist[child_v] = dist[v]+wt;
                st.insert({dist[child_v],child_v});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,k;
    cin>>n>>m>>k;

    vector<pair<int,int>>g[n+1];
    vector<int>dist(n+1,INF);
    vector<int>vis(n+1,0);

    for(int i=0;i<m;i++)
    {
        int x,y,wt;
        cin>>x>>y>>wt;
        g[x].push_back({y,wt});
    }

    ll ans=0;

    set<pair<int,int>>st;

    while(k--)
    {
        int x,wt;
        cin>>x>>wt;
        dist[x]=wt;
        st.insert({wt,x});
    }

    dijkstra(1,g,dist,vis);

    for(int i=1;i<=n;i++)
    {
        cout<<dist[i]<<" ";
    }
    cout<<endl;

    for(auto e:st)
    {
        int v=e.second;
        int v_dist=e.first;

        if(dist[v]!=v_dist)
        {
            ans++;
        }
    }
    cout<<ans<<endl;
}
