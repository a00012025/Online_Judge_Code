#include<bits/stdc++.h>
using namespace std;

char s[1001],t[1001] ;
int n,m ;
bool check(int x)
{
    if(!x) return 1 ;
    for(int i=0;i<x;i++) if(s[i]!=t[m-x+i]) return 0 ;
    return 1 ;
}
main()
{
    scanf("%s%s",s,t) ;
    n=strlen(s) , m=strlen(t) ;
    for(int i=min(n,m);i>=0;i--)
    {
        if(check(i)) { printf("%d\n",i) ; return 0 ; }
    }
}
