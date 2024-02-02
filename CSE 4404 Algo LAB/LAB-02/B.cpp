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

    ll s,n;
    cin>>s>>n;
    vector<pair<ll,ll>>v;
    for(ll i=0;i<n;i++)
    {
        ll x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    sort(v.begin(),v.end());

    for(ll i=0;i<n;i++)
    {
        if(s>v[i].first)
        {
            s+=v[i].second;
        }
        else
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
}