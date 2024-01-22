#include<bits/stdc++.h>
typedef long long int ll;
#include <chrono>
using namespace std;

const int N=1e5;
const int INF=1e9+10;

int find_peak(vector<vector<ll>>v,int n,int m)
{
    int sn=n/2, sm=m/2;
    int rs=-INF, ls=-INF, us=-INF, ds=-INF;

    if(sn-1>=0) ls=v[sn-1][sm];
    if(sn+1<n) rs=v[sn+1][sm];
    if(sm-1>=0) us=v[sn][sm-1];
    if(sm+1<m) ds=v[sn][sm+1];

    int mx=max({ls,rs,us,ds});
    if(v[sn][sm]>=mx) return v[sn][sm];
    
    if(mx==ls) return find_peak(v,sn-1,sm);
    else if(mx==rs) return find_peak(v,sn+1,sm);
    else if(mx==us) return find_peak(v,sn,sm-1);
    else return find_peak(v,sn,sm+1);
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

    clock_t start = clock();

    int peak=find_peak(a,n,m);
    //cout<<v[peak]<<" "<<peak<<"\n";

    // End the timer
    clock_t end = clock();

    // Calculate the duration
    double cpu_time_used = ((double) (end - start));

    // Print the duration in seconds
    cout<<cpu_time_used<<"\n";
}