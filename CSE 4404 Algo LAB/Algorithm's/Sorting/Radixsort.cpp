#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

const int N=1e5;
const int INF=1e9+10;

void countSort(vector<int> &arr, int exp)
{
    vector<int> output(arr.size());
    vector<int> count(10, 0);

    for(int i=0; i<arr.size(); i++)
        count[(arr[i]/exp)%10]++;

    for(int i=1; i<10; i++)
        count[i]+=count[i-1];

    for(int i=arr.size()-1; i>=0; i--)
    {
        output[count[(arr[i]/exp)%10]-1]=arr[i];
        count[(arr[i]/exp)%10]--;
    }

    for(int i=0; i<arr.size(); i++)
        arr[i]=output[i];
}

void radixSort(vector<int> &arr)
{
    int mx=*max_element(arr.begin(), arr.end());

    for(int exp=1; mx/exp>0; exp*=10)
        countSort(arr, exp);
}

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}