//Fenwick Tree or BIT
//To get the next index
//Author : Infra
#include <iostream>

using namespace std;

int main()
{
    int i;
    cin>>i;
    cout<<(i^1<<(log2(i&-i)));
    //or we can use ffs(i) -1 , when we use bits/stdc++.h
    //ffs(i)==log2(i&-1)+1
    return 0;
}
