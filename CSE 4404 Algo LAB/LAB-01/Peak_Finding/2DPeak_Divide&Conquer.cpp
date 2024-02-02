#include<bits/stdc++.h>
typedef long long int ll;
#include <chrono>
using namespace std;

const int N=1e5;
const int INF=1e9+10;

int peak_find(vector<vector<ll>>v,int l,int r)
{
    int m=(r/2);
    int mx=-INF;
    int idx=-1;
    for(int i=0;i<v.size();i++)
    {
        if(v[i][m]>mx)
        {
            mx=v[i][m];
            idx=i;
        }
    }

    int rs=-INF, ls=-INF, us=-INF, ds=-INF;

    if(idx-1>=0) ls=v[idx-1][m];
    if(idx+1<v.size()) rs=v[idx+1][m];
    if(m-1>=0) us=v[idx][m-1];
    if(m+1<v[0].size()) ds=v[idx][m+1];

    int mx1=max({ls,rs,us,ds});
    if(v[idx][m]>=mx1) return v[idx][m];

    if(mx1==ls) return peak_find(v,l,m-1);
    else if(mx1==rs) return peak_find(v,m+1,r);
    else if(mx1==us) return peak_find(v,l,m-1);
    else return peak_find(v,m+1,r);
}

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;

    vector<vector<ll>> a(n,vector<ll>(m));

    for(int i=0; i<n; i++)
    {
        for(int j=0;j<m;j++)
        {
            a[i][j]=i+j;
        }
    }

    int peak=peak_find(a,0,m-1);
    cout<<peak<<"\n";
}