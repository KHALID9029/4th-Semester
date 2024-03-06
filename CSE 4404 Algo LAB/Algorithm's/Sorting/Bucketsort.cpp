#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

const int N=1e5;
const int INF=1e9+10;

void bucketSort(vector<int> &arr)
{
    int n=arr.size();
    vector<int> b[n];

    for(int i=0; i<n; i++)
    {
        int bi=n*arr[i];
        b[bi].push_back(arr[i]);
    }

    for(int i=0; i<n; i++)
        sort(b[i].begin(), b[i].end());

    int index=0;
    for(int i=0; i<n; i++)
        for(int j=0; j<b[i].size(); j++)
            arr[index++]=b[i][j];
}



int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}