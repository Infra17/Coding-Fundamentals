#include <bits/stdc++.h>
using namespace std;

//Multiplication and Remainder for big numbers using string

string multiply(string s,string s1)
{
    int carry=0;
    int a=stoi(s1);
    for(int i=s.length()-1;i>=0;i--)
    {
        carry+=(s[i]-'0')*a;
        s[i]= (carry%10+'0');
        //cout<<carry<<" "<<i<<endl;
        carry=carry/10;
    }
    if(carry) s=to_string(carry)+s;
    return s;
}

int remainder(string s1,string s2)
{
    int carry=0;
    for(int i=0;i<s1.length();i+=s2.length())
    {
        carry=pow(10,s2.length())*carry+stoi(s1.substr(i,s2.length()));
        carry%=stoi(s2);
        //cout<<stoi(s1.substr(i,s2.length()))<<" "<<carry<<endl;
    }
    return carry;
}

int main()
{
    cout<<multiply("15","4")<<endl;
    cout<<remainder("21","4");
}
