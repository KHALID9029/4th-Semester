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

    ll b,s;
    cin>>b>>s;
    ll t=1;
    while(b!=0 && s!=0)
    {
        vector<ll>bb(b),ss(s);
        for(ll i=0;i<b;i++)
        {
            cin>>bb[i];
        }
        for(ll i=0;i<s;i++)
        {
            cin>>ss[i];
        }
        sort(bb.begin(),bb.end());
        sort(ss.begin(),ss.end());

        if(b<=s) cout<<"Case "<<t<<": 0\n";
        else cout<<"Case "<<t<<": "<<b-s<<" "<<bb[0]<<"\n";
        t++;
        cin>>b>>s;
    }
}