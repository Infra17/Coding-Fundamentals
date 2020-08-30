//A Trie program and implimentation for autocompleting maximum three words
//Author : Infra

#include <bits/stdc++.h>
using namespace std;

struct trie
{
    struct trie *child[26];
    bool ifend;
    trie()
    {
        memset(child,0,sizeof(child));
        ifend=false;
    }
};
struct trie *root;

void insert(string s)
{
    struct trie *cur=root;
    for(char c:s)
    {
        int index=c-'a';
        if(cur->child[index]==NULL)
        {
            cur->child[index]=new trie;
        }
        cur=cur->child[index];
    }
    cur->ifend=true;
}

bool search(string s)
{
    struct trie *cur=root;
    for(char c:s)
    {
        int index=c-'a';
        if(cur->child[index]==NULL) return false;
        cur=cur->child[index];
    }
    return cur->ifend;
}

void autocomp(string s)
{
    string st;int co=3;
    struct trie *cur=root;
    for(char c:s)
    {
        int index=c-'a';
        if(cur->child[index]==NULL) {cout<<"No match"<<endl;return;}
        cur=cur->child[index];
    }
    if(cur->ifend) {cout<<s<<endl;co--;}
    
    
}


int main()
{
    root=new trie;
    int n;string s;
    cin>>n; //how many words to insert
    while(n--)
    {
        cin>>s;insert(s);
    }
    cin>>n; //how many to search
    while(n--)
    {
        cin>>s;
        if(search(s)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    cin>>n; //How many to autocomplete upto 3 words
    while(n--) 
    {
        cin>>s;
        autocomp(s);
    }
    
    
    
    return 0;
}
