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

int autocomp(string s,int co)
{
    if(co==0) return 0;
    string st;
    struct trie *cur=root;
    for(char c:s)
    {
        int index=c-'a';
        if(cur->child[index]==NULL) {return co;}
        cur=cur->child[index];
    }
    if(cur->ifend) {cout<<s<<endl;co--;}
    
    char ch;
    for(int i=0;i<26;i++)
    {
        if(cur->child[i]) {ch='a'+i;co=autocomp(s+ch,co);}
        if(co==0) return 0;
    }
    
    return co;
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
    int co;
    cin>>co; //How many autocomplete suggestion maximum to give
    while(n--) 
    {
        cin>>s;
        if(autocomp(s,co)==3) cout<<"No Match"<<endl;
    }
    
    
    
    return 0;
}
