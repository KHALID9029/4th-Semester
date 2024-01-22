#include<bits/stdc++.h>
typedef long long int ll;
#include <chrono>
using namespace std;

const int N=1e5;
const int INF=1e9+10;

int peak_find(vector<int> arr)
{
    int len = arr.size();
    int left = 0, right = len - 1;
    while(left <= right){
        int mid = (left + right) / 2;
        if(arr[mid] >= arr[mid - 1] && arr[mid] >= arr[mid + 1]){
            return arr[mid];
        }
        else if(arr[mid] < arr[mid - 1]){
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    
    }

    return -1;

}

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int>a;
    for(int i=0; i<n; i++) 
    {
        a.push_back(i);
    }

    int l=0,r=n-1;
    clock_t start = clock();

    int peak=peak_find(a);
    //cout<<v[peak]<<" "<<peak<<"\n";

    // End the timer
    clock_t end = clock();

    // Calculate the duration
    double cpu_time_used = ((double) (end - start));

    // Print the duration in seconds
    cout<<cpu_time_used<<"\n";
}