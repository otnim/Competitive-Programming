#include <bits/stdc++.h>
using namespace std;
#define     SZ  5000000
#define     in  freopen("in.txt", "r", stdin)

int n, ara[SZ], tmp[SZ];

void Merge(int lo, int mid, int hi)
{
    int i, j, k, n1, n2;
    n1 = mid - lo + 1;
    n2 = hi - mid;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++) L[i] = ara[lo+i];
    for (i = 0; i < n2; i++) R[i] = ara[mid+i+1];
    i = j = 0;
    k = lo;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j]) ara[k++] = L[i++];
        else ara[k++] = R[j++];
    }

    while (i < n1) ara[k++] = L[i++];
    while (j < n2) ara[k++] = R[j++];

    for (i = 0; i < n; i++)cout<<ara[i]<<"  ";
    cout<<endl;
}

void mergeSort(int lo, int hi)
{
    if (lo < hi){
    int mid = (lo+hi)/2;

    mergeSort(lo, mid);
    mergeSort(mid+1, hi);
    //cout<<"H  lo = "<<lo<<"  hi = "<<hi<<"  mid = "<<mid<<endl;
    Merge(lo, mid, hi);
    }
}

int main()
{
    cin>>n;
    for(int i = 0; i < n; i++) cin>>ara[i]; //0 indexing
    mergeSort(0, n-1);

    for (int i = 0; i < n; i++) cout<<ara[i]<<" ";
    cout<<endl;
}
