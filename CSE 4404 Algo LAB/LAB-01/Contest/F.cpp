#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

const int N=1e5;
const int INF=1e9+10;

ll bubbleSort(vector<ll>arr, int n) 
{
    ll count=0;
    for (ll i = 0; i < n - 1; i++) 
    {
        for (ll j = 0; j < n - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                swap(arr[j], arr[j + 1]);
                count++;
            }
        }
    }
    return count;
}

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
        vector<ll>v(n);
        for(ll i=0;i<n;i++)
        {
            cin>>v[i];
        }
        cout<<"Optimal train swapping takes "<<bubbleSort(v,n)<< " swaps."<<"\n";
    }
}