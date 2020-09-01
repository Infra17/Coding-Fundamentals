//Bubble sort 
//Inplace, stable 
//Author: Infra
//Time Complexty : Best O(n), avg/worst O(n^2)
//Space Complexity : O(1)


#include <bits/stdc++.h>
using namespace std;

vector<int> arr(10000);

void Bubblesort(int n)
{
    for(int i=n-1;i>0;i--)
    {int flag=1;
        for(int j=0;j<=i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {swap(arr[j],arr[j+1]);flag=0;}
        }
        if(flag) return;
    }
        
    
}

int main()
{
    int a,n;
    cin>>n;
    for(int i=0;i<n;i++)
    {cin>>arr[i];}
    Bubblesort(n);
    for(int i=0;i<n;i++)
    {cout<<arr[i]<<" ";}
}
