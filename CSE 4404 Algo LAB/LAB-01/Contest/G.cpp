#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

const int N=1e5;
const int INF=1e9+10;

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;
    vector<ll>v(n+1);
    for(ll i=1;i<=n;i++)
    {
        cin>>v[i];
    }
    sort(v.begin(),v.end());

    ll ans=0,day=1;
    for(ll i=1;i<=n;i++)
    {
       if(v[i]>=day) {ans++; day++;}
       //cout<<v[i]<<" "<<ans<<" "<<day<<"\n";
    }

    cout<<ans<<"\n";
}