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
    vector<ll>v(n),even,odd;
    for(ll i=0;i<n;i++)
    {
        cin>>v[i];
        if(v[i]%2==0) even.push_back(v[i]);
        else odd.push_back(v[i]);
    }
    sort(even.begin(),even.end());
    sort(odd.begin(),odd.end());

    ll ne=even.size(),no=odd.size();
    if(ne==no || ne==no-1 || ne==no+1) {cout<<0; return 0;}

    if(ne>no)
    {
        ne-=(no+1);
        ll ans=0;
        for(ll i=0;i<ne;i++) ans+=even[i];
        cout<<ans;
        return 0;
    }

    no-=(ne+1);
    ll ans=0;
    for(ll i=0;i<no;i++) ans+=odd[i];
    cout<<ans;
    return 0;
}