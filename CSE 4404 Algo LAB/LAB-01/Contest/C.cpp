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
    ll a[n];
    for(ll i=0; i<n; i++)
        cin>>a[i];

    sort(a, a+n);
    ll ans=0;

    for(ll i=0; i<n;i+=2)
    {
        ans+=a[i+1]-a[i];
    }
    cout<<ans<<endl;
}