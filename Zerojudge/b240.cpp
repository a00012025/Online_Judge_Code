#include<stdio.h>
#include<string.h>
#include<string>
#include<map>
#include<iostream>
#include<algorithm>
using namespace std;
map<char,int> mp ;
string st="XOBCDAFGHUJKLMNIPQRSTEVWYZ" ;

bool st_greater(string x,string y)
{
    for(int i=0;i<x.size() && i<y.size();i++)
        if(mp[x[i]]!=mp[y[i]]) return mp[x[i]]>mp[y[i]] ;
    return x.size()>y.size() ;
}

struct P{int id,year ; string author,name ;}p[200];
bool cmp(P x,P y)
{
    if(x.author!=y.author) return st_greater(y.author,x.author) ;
    if(x.year!=y.year) return x.year<y.year ;
    return st_greater(y.name,x.name) ;
}
main()
{
    for(int i=0;i<26;i++) {mp[st[i]]=i ; mp[st[i]-'A'+'a']=i ;}
    mp[' ']=-1 ;
    int n ; scanf("%d",&n) ;
    char s[500] ; string tmp ; fgets(s,499,stdin) ;
    for(int i=0;i<n;i++)
    {
        fgets(s,499,stdin) ; tmp.clear() ;
        for(int j=0;s[j]!='\0';j++) tmp.push_back(s[j]) ;
        p[i].author.clear() ; p[i].name.clear() ;
        int j ;
        for(j=0;tmp[j]!=',';j++) p[i].author.push_back(tmp[j]) ;
        for(j=j+2;tmp[j+1]!='(';j++) p[i].name.push_back(tmp[j]) ;
        int &y=p[i].year ; y=0 ;
        for(j=j+2;tmp[j]!=')';j++) {y*=10 ; y+=tmp[j]-'0' ;}
    }
    sort(p,p+n,cmp) ;
    for(int i=0;i<n;i++)
    {
        cout << p[i].author << ", " << p[i].name << " (" << p[i].year << ')' << endl ;
    }
}
