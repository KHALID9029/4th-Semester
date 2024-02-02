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

    string s;
    cin>>s;
    vector<ll> v;
    ll n=s.length();
    for(ll i=0; i<n; i++)
    {
        if(s[i]=='1')
            v.push_back(1);
        else if(s[i]=='2')
            v.push_back(2);
        else if(s[i]=='3')
            v.push_back(3);
    }

    sort(v.begin(), v.end());
    n=v.size();

    for(ll i=0; i<n; i++)
    {
        cout<<v[i];
        if(i!=n-1)
            cout<<"+";
    }
}