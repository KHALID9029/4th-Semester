#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

const int N=1e5;
const int INF=1e9+10;

void swap(int &a, int &b) 
{
    int temp = a;
    a = b;
    b = temp;
}

void bubbleSort(vector<ll>arr, int n) 
{
    for (ll i = 0; i < n - 1; i++) 
    {
        for (ll j = 0; j < n - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}


int main() 
{
    int n;
    cin>>n;
    vector<ll>v;
    for(ll i=0; i<n; i++) 
    {
        v.push_back(i);
    }

    clock_t start = clock();

    bubbleSort(v, n);

    clock_t end = clock();

    double cpu_time_used = ((double) (end - start));

    // Print the duration in seconds
    cout<<cpu_time_used<<"\n";

    return 0;
}
