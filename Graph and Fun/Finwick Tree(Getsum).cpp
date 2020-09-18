//Fenwick or Binary Indexed Tree
//Author : Infra

#include <bits/stdc++.h>
using namespace std;

class BIT 
{
    int size;int *table;
    public:
    BIT(int size)
    {
        this->size=size;
        table = new int[size+1];
        memset(table,0,sizeof(table));
    }
    void update(int i,int value)
    {
        while(i<=size)
        {
            table[i]+=value;
            i+=(i&-i);
        }
    }
    int getsum(int i)
    {int sum=0;
        while(i>0)
        {
            sum+=table[i];
            i-=(i&-i);
        }
        return sum;
    }
};

int main()
{
    int n,a;cin>>n;
    BIT arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>a;
        arr.update(i+1,a);
    }
    for(int i=0;i<n;i++)
    cout<<arr.getsum(i+1)<<" ";
    //We can update and then ask for sums in a range in o(log(n)) time
    return 0;
}
