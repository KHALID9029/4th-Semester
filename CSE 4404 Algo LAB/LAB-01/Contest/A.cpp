#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

const int N=1e5;
const int INF=1e9+10;

void merge(vector<ll>&v,ll l, ll r,ll &count)
{
    ll mid=(l+r)/2;
    ll i=l,j=mid+1;
    vector<ll>temp;
    while(i<=mid && j<=r)
    {
        if(v[i]<v[j])
        {
            temp.push_back(v[i]);
            i++;
        }
        else
        {
            temp.push_back(v[j]);
            j++;
            count++;
            count+=mid-i;
        }
    }
    while(i<=mid)
    {
        temp.push_back(v[i]);
        i++;
    }
    while(j<=r)
    {
        temp.push_back(v[j]);
        j++;
    }
    for(ll i=l;i<=r;i++)
    {
        v[i]=temp[i-l];
    }

}

void mergesort(vector<ll>&v,ll l,ll r,ll &count)
{
    if(l>=r)
    {
        return;
    }
    ll mid=(l+r)/2;
    mergesort(v,l,mid,count);
    mergesort(v,mid+1,r,count);
    merge(v,l,r,count);
}

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;
    string s;
    getline(cin, s);
    while(t--)
    {
        ll n;
        cin>>n;
        vector<ll> v;
        for(ll i=0;i<n;i++)
        {
            ll x;
            cin>>x;
            v.push_back(x);
        }
        getline(cin, s);

        ll ans=0;
        mergesort(v,0,n-1,ans);

        //for(auto i:v) {cout<<i<<" ";} cout<<endl;

        cout<<ans<<endl;
    }
}