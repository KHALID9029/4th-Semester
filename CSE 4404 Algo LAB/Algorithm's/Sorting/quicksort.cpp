#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

const int N=1e5;
const int INF=1e9+10;

ll partition(vector<ll> &v, ll p, ll r)
{
    ll x=v[r];
    ll i=p-1,j=p;
    for(;j<=r;j++)
    {
        if(v[j]<=x)
        {
            i++;
            swap(v[i],v[j]);
        }
    }
    swap(v[i+1],v[r]);
    return i;
}

void quicksort(vector<ll> &v, ll p, ll r)
{
    if(p>=r)
    {
        return;
    }
    
    ll q=partition(v,p,r);
    //cout<<q<<endl;
    quicksort(v,p,q-1);
    quicksort(v,q+1,r);
    
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

    quicksort(v,0,n-1);
    for(ll i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}