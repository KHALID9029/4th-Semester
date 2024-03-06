#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

const int N=1e5;
const int INF=1e9+10;

void countingsort(vector<ll> &v, ll n)
{
    ll max=*max_element(v.begin(),v.end());
    vector<ll> count(max+1,0);
    for(ll i=0;i<n;i++)
    {
        count[v[i]]++;
    }
    for(ll i=1;i<=max;i++)
    {
        count[i]+=count[i-1];
    }
    vector<ll> output(n);
    for(ll i=n-1;i>=0;i--)
    {
        output[count[v[i]]-1]=v[i];
        count[v[i]]--;
    }
    for(ll i=0;i<n;i++)
    {
        v[i]=output[i];
    }
}

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;
    vector<ll> v(n);
    for(ll i=0;i<n;i++)
    {
        cin>>v[i];
    }
    countingsort(v,n);
    for(ll i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }
}