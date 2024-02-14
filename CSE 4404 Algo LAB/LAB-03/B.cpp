#include<iostream>
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

    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll x=(n*(n-1))/2;
        ll a[n],b[x],i;

        for(i=0;i<x;i++)
        {
            cin>>b[i];

        }
        sort(b,b+x);

        ll check=n,k=0;
        for(i=0;i<x;i+=check)
        {
            a[k]=b[i];
            k++;
            check--;
        }

        a[n-1]=1000000000;

        for(i=0;i<n;i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
}