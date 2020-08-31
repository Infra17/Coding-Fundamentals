//Quick sort 
//Not stable, divide and conquer, recursive
//Author: Infra
//Time Complexty :
//Best/Avg case : O(nlogn)
//Worst case(rare by using random pivot partition) : O(n^2)
//Space Complexity : avg case: O(logn), worst case: O(n)


#include <bits/stdc++.h>
using namespace std;

vector<int> arr(10000);

int partition(int start,int end)
{
    int pivot=arr[end];
    int pIndex=start;
    for(int i=start;i<end;i++)
    {
        if(arr[i]<=pivot)
        {
            swap(arr[i],arr[pIndex]);
            pIndex++;
        }
    }
    swap(arr[pIndex],arr[end]);
    return pIndex;
}

int random_partition(int start,int end)
{
    //srand(time(NULL)); 
    /*
    The srand() function in C++ seeds the pseudo random number generator
    used by the rand() function. ... It means that if no srand() is called
    before rand(), the rand() function behaves as if it was seeded with srand(1).
    */
    int random=start+rand()%(end-start);
    swap(arr[random],arr[end]);
    return partition(start,end);
}

void Quicksort(int start,int end)
{
    if(start>=end) return;
    int pivot_partition=random_partition(start,end) ;
    Quicksort(start,pivot_partition-1);
    Quicksort(pivot_partition+1,end);
}

int main()
{
    int a,n;
    cin>>n;
    for(int i=0;i<n;i++)
    {cin>>arr[i];}
    Quicksort(0,n-1);
    for(int i=0;i<n;i++)
    {cout<<arr[i]<<" ";}
}
