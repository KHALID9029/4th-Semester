#include<bits/stdc++.h>
typedef long long int ll;
#include <chrono>
#include<time.h>
using namespace std;

const int N=1e5;
const int INF=1e9+10;

int peak_find(vector<int>a)
{
    int n=sizeof(a)/sizeof(a[0]);

    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            if(a[i]>=a[i+1])
            {
               return i;
            }
        }
        else if(i==n-1)
        {
            if(a[i]>=a[i-1])
            {
                return i;
            }
        }
        else
        {
            if(a[i]>=a[i-1] && a[i]>=a[i+1])
            {
                return i;
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
    std::srand(std::time(0));


    int n;
    cin>>n;
    vector<int>v;
    for(int i=0; i<n; i++) 
    {
        v.push_back(i);
    }

    clock_t start = clock();

    int peak=peak_find(v);
    //cout<<v[peak]<<" "<<peak<<"\n";

    // End the timer
    clock_t end = clock();

    // Calculate the duration
    double cpu_time_used = ((double) (end - start));

    // Print the duration in seconds
    cout<<cpu_time_used<<"\n";
}