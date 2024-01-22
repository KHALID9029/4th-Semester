#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

const int N=1e5;
const int INF=1e9+10;


void insertionSort(int arr[], int n) 
{
    for (int i = 1; i < n; i++) 
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}



int main() 
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) 
    {
        arr[i]=i;
    }

    insertionSort(arr, n);

    return 0;
}
