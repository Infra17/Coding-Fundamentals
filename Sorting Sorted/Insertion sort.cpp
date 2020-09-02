//Insertion sort 
//Inplace, stable, better than selection and bubble sort
//Author: Infra
//Time Complexty : Best O(n), avg/worst O(n^2)
//Space Complexity : O(1)


#include <bits/stdc++.h>
using namespace std;

vector<int> arr(10000);

void Insertionsort(int n)
{
    for(int i=1;i<n;i++)
    {
        int j=i,value=arr[i];
        while(j>0 && arr[j-1]>value)
        {
            arr[j]=arr[j-1];j--;
        }
        arr[j]=value;
    }
        
    
}

int main()
{
    int a,n;
    cin>>n;
    for(int i=0;i<n;i++)
    {cin>>arr[i];}
    Insertionsort(n);
    for(int i=0;i<n;i++)
    {cout<<arr[i]<<" ";}
}
