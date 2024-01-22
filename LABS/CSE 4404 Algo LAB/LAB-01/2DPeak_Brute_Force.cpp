#include<bits/stdc++.h>
typedef long long int ll;
#include <chrono>
using namespace std;

const int N=1e5;
const int INF=1e9+10;

int find_peak(vector<vector<ll>>v,int n,int m)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i==0 && j==0)
            {
                if(v[i][j]>=v[i+1][j] && v[i][j]>=v[i][j+1])
                {
                    return v[i][j];
                }
            }
            else if(i==0 && j==m-1)
            {
                if(v[i][j]>=v[i+1][j] && v[i][j]>=v[i][j-1])
                {
                    return v[i][j];
                }
            }
            else if(i==n-1 && j==0)
            {
                if(v[i][j]>=v[i-1][j] && v[i][j]>=v[i][j+1])
                {
                    return v[i][j];
                }
            }
            else if(i==n-1 && j==m-1)
            {
                if(v[i][j]>=v[i-1][j] && v[i][j]>=v[i][j-1])
                {
                    return v[i][j];
                }
            }
            else if(i==0)
            {
                if(v[i][j]>=v[i+1][j] && v[i][j]>=v[i][j-1] && v[i][j]>=v[i][j+1])
                {
                    return v[i][j];
                }
            }
            else if(i==n-1)
            {
                if(v[i][j]>=v[i-1][j] && v[i][j]>=v[i][j-1] && v[i][j]>=v[i][j+1])
                {
                    return v[i][j];
                }
            }
            else if(j==0)
            {
                if(v[i][j]>=v[i-1][j] && v[i][j]>=v[i+1][j] && v[i][j]>=v[i][j+1])
                {
                    return v[i][j];
                }
            }
            else if(j==m-1)
            {
                if(v[i][j]>=v[i-1][j] && v[i][j]>=v[i+1][j] && v[i][j]>=v[i][j-1])
                {
                    return v[i][j];
                }
            }
            else
            {
                if(v[i][j]>=v[i-1][j] && v[i][j]>=v[i+1][j] && v[i][j]>=v[i][j-1] && v[i][j]>=v[i][j+1])
                {
                    return v[i][j];
                }
            }
        }
    }
}

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;

    vector<vector<ll>> a(n,vector<ll>(m));

    for(int i=0; i<n; i++)
    {
        for(int j=0;j<m;j++)
        {
            a[i][j]=i+j;
        }
    }

    clock_t start = clock();

    int peak=find_peak(a,n,m);
    //cout<<v[peak]<<" "<<peak<<"\n";

    // End the timer
    clock_t end = clock();

    // Calculate the duration
    double cpu_time_used = ((double) (end - start));

    // Print the duration in seconds
    cout<<cpu_time_used<<"\n";
}