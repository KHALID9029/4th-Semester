#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

const int N=1e5;
const int INF=1e9+10;

void merge(vector<ll>&v,ll l, ll r)
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

void mergesort(vector<ll>&v,ll l,ll r)
{
    if(l>=r)
    {
        return;
    }
    ll mid=(l+r)/2;
    mergesort(v,l,mid);
    mergesort(v,mid+1,r);
    merge(v,l,r);
}

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<ll>v={1,5,2,3,4};
    mergesort(v,0,v.size()-1);
    for(auto i:v)
    {
        cout<<i<<" ";
    }
}