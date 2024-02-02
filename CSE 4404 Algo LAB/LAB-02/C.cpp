#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

const int N=1e5;
const int INF=1e9+10;

int custom(pair<int,int>&a, pair<int,int>&b)
{
    if(a.first!=b.first)
    {
        return a.first<b.first;
    }
    return a.second<b.second;
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
    getline(cin,s);

    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<string>v(m);
        vector<pair<int,int>>v1(m);

        for(int i=0;i<m;i++)
        {
            string ss;
            cin>>ss;
            v[i]=ss;
            int count=0;

            for(ll j=0;j<n;j++)
            {
                for(ll k=j+1;k<n;k++)
                {
                    if(ss[j]>ss[k])
                    {
                        count++;
                    }
                }
            }
            //cout<<count<<endl;
            v1[i]={count,i};
            
        }

        sort(v1.begin(),v1.end(),custom);

        for(auto i:v1)
        {
            cout<<v[i.second]<<endl;
        }
        if(t!=0)
        {
            cout<<endl;
        }
    }
}