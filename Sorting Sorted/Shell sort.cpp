//Shell sort 
//Inplace, unstable, better than Insertion sort
//Author: Infra
//Time Complexty : Best O(n), avg/worst O(n^1.25) or O(n^1.5)
//Space Complexity : O(1)


#include <bits/stdc++.h>
using namespace std;

vector<int> arr(10000);

void Shellsort(int n)
{
    int i,j,increment,temp;
    for(increment=n/2;increment>0;increment/=2)
    for(i=increment;i<n;i++)
    {
        temp=arr[i];
        for(j=i;j>=increment;j-=increment)
        if(temp<arr[j-increment]) arr[j]=arr[j-increment];
        else break;
        
        arr[j]=temp;
    }
}

int main()
{
    int a,n;
    cin>>n;
    for(int i=0;i<n;i++)
    {cin>>arr[i];}
    Shellsort(n);
    for(int i=0;i<n;i++)
    {cout<<arr[i]<<" ";}
}
