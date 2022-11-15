#include <bits/stdc++.h>
using namespace std;
#define     SZ  500000

int n, ara[SZ];

int parti(int lo, int hi)
{
    int i, j, t, pivot;
    pivot = ara[hi];
    for (i = lo-1, j = lo; j < hi; j++)
    {
        if (ara[j] < pivot)
        {
            swap(ara[++i], ara[j]);
        }
    }
    swap(ara[hi], ara[i+1]);
    return i+1;

}
void quickSort(int lo, int hi)
{
    if (lo >= hi) return;

    int p = parti(lo, hi);

    quickSort(lo, p-1);
    quickSort(p+1, hi);

}

int main()
{
    cin>>n;
    for (int i = 0; i < n; i++) cin>>ara[i];

    quickSort(0, n-1);

    for (int i = 0; i < n; i++) cout<<ara[i]<<"  ";

}
