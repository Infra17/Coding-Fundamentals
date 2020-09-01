//Selection sort 
//Author: Infra
//Time Complexty : O(n^2)
//Space Complexity : O(1)


#include <bits/stdc++.h>
using namespace std;

vector<int> arr(10000);

void Selectionsort(int n)
{
    for(int i=0;i<n-1;i++)
    {
        int imin=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[imin])
            imin=j;
        }
        swap(arr[i],arr[imin]);
    }
}

int main()
{
    int a,n;
    cin>>n;
    for(int i=0;i<n;i++)
    {cin>>arr[i];}
    Selectionsort(n);
    for(int i=0;i<n;i++)
    {cout<<arr[i]<<" ";}
}
