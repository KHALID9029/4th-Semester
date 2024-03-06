#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

const int N=1e5;
const int INF=1e9+10;

void heapify(vector<ll>& v, ll n, ll i) 
{
    ll largest = i;      
    ll left = 2 * i + 1;  
    ll right = 2 * i + 2; 

    
    if (left < n && v[left] > v[largest])
        largest = left;

   
    if (right < n && v[right] > v[largest])
        largest = right;

    
    if (largest != i) 
    {
        swap(v[i], v[largest]);
        heapify(v, n, largest);
    }
}

void heapSort(vector<ll>& v) 
{
    ll n = v.size();

    
    for (ll i = n / 2 - 1; i >= 0; i--)
        heapify(v, n, i);

    
    for (int i = n - 1; i > 0; i--) 
    {
        swap(v[0], v[i]);
        heapify(v, i, 0);
    }
}


int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<ll>v={10,8,9,7,6,5,4,3,2,1};
    heapSort(v);
    for(auto i:v)
    {
        cout<<i<<" ";
    }
}