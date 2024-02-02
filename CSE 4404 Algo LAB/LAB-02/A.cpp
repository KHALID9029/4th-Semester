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
    int n,flag=0,i;
    cin>>n;
    int a[n],b[n];
    for(i=0;i<n;i++)
        {
            cin>>a[i]>>b[i];
            if(a[i]!=b[i]) {flag=1;}
        }
    if(flag) {cout<<"Happy Alex"<<endl;}
    else {cout<<"Poor Alex"<<endl;}
}