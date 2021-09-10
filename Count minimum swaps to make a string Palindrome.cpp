#include <bits/stdc++.h>
using namespace std;
string s;

bool IfPossible()
{
    unordered_map<char,int> m;
    int v=0;
    for(auto i:s) m[i]++;
    for(auto i:m) if((i.second&1)!=0) v++;
    if(v>1) return false;
    return true;
}

int main()
{
    getline(cin,s);
    if(IfPossible()==false) {cout<<-1; return 0;}

    int l=0,r=s.length()-1,k,c=0;
    while(l<r)
    if(s[l]!=s[r])
    {
        k=r;
        while(s[l]!=s[k]) k--;
        swap(s[r],s[k]);
        c++;
        //cout<<s<<endl;
    }
    else { l++;r--; }
    cout<<c;
}
