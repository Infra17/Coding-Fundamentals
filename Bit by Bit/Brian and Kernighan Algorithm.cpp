//Count set bits by Brian and Kerninghan Algorithm and others
//Author : Infra

#include <bits/stdc++.h>
using namespace std;

int Brutforce(int n) //o(logn) approach
{
    int c=0;
    while(n)
    {
        c+=n&1;
        n>>=1;
    }
    return c;
}

int BrianKerninghan(int n) //using toggling effect if right most bit is 0
{
    int c=0;
    while(n)
    {
        c++;
        n&=(n-1);
    }
    return c; //o(logn) in worst case, basically o(the value of solution)
}

int Lookup(int n) //o(logn /k) approach, if there is more set bits, space-> o(2^k)
{
    int table[]={0,1,1,2,1,2,2,3,1,2, 2, 3, 2, 3, 3, 4};
    //          {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15}
    
    int c=0;
    while(n)
    {
        c+=table[n&15];
        n>>=4; //here k=4;0xf->15 (1111)
    }
    return c;
}

int main()
{
    int n;
    cin>>n;
    cout<<Brutforce(n)<<" "<<BrianKerninghan(n)<<" "<<Lookup(n)<<" ";
    cout<<__builtin_popcount(n);//built in function in gcc
}
