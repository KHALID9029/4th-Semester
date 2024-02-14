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
    vector<ll> v(n);
    vector<ll> v1(n);
    for(ll i=0;i<n;i++)
    {
        cin>>v[i];
        v1[i]=v[i];
    }
    sort(v1.begin(),v1.end());
    ll l=0,r=0;
    for(ll i=0;i<n;i++)
    {
        if(v[i]!=v1[i])
        {
            l=i;
            break;
        }
    }
    for(ll i=n-1;i>=0;i--)
    {
        if(v[i]!=v1[i])
        {
            r=i;
            break;
        }
    }

    if(l==0 && r==0)
    {
        cout<<"yes"<<endl;
        cout<<1<<" "<<1<<endl;
    }
    else
    {
        reverse(v.begin()+l,v.begin()+r+1);
        if(v==v1)
        {
            cout<<"yes"<<endl;
            cout<<l+1<<" "<<r+1<<endl;
        }
        else
        {
            cout<<"no"<<endl;
        }
    }
}