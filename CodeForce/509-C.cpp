#include<bits/stdc++.h>
using namespace std;
const int maxn=500+10 ;

void print(const string &s)
{
    for(int i=0,j=0;i<maxn;i++) if(s[i]!='0'||j)
        printf("%c",s[i]) , j=1 ;
    printf("\n") ;
}

int s0[maxn] ;
inline int gets(int x,int y){return x?s0[y]-s0[x-1]:s0[y] ;}
string solve(string &s,int S)
{
    reverse(s.begin(),s.end()) ;
    for(int i=0;i<maxn;i++) s0[i]=i?s0[i-1]+s[i]-'0':s[i]-'0' ;
    for(int i=0;;i++)
    {
        if(s[i]=='9') continue ;
        if(gets(i,maxn-1)+1>S || gets(i,maxn-1)+9-(s[i]-'0')+9*i<S)
            continue ;

        int las=S-(gets(i,maxn-1)+1) ;
        string t ; t.resize(maxn) ;
        for(int j=0;j<maxn;j++) t[j]=(j>=i?s[j]:'0') ;
        t[i]++ ;
        for(int j=0;j<i && las;j++) t[j]=min(9,las)+'0' , las-=min(9,las) ;
        while(las--) t[i]++ ;
        reverse(t.begin(),t.end()) ;
        return t ;
    }
}

string s ;
main()
{
    int n ; scanf("%d",&n) ;
    s.resize(maxn) ;
    for(int i=0;i<maxn;i++) s[i]='0' ;
    while(n--)
    {
        int S ; scanf("%d",&S) ;
        s=solve(s,S) ;
        print(s) ;
    }
}
