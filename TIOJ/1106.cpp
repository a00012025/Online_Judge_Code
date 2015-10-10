#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10 ;

char s[maxn] ;
int leaf,maxdep,maxson ;
int now ;

void dfs(int dep)
{
    maxdep=max(maxdep,dep) ;
    if(s[now]=='*') { leaf++ ; now++ ; return ; }
    int son=0 ;
    now++ ;
    while(s[now]!=')')
    {
        son++ ;
        dfs(dep+1) ;
    }
    now++ ;
    maxson=max(maxson,son) ;
}

main()
{
    while(scanf("%s",s)!=EOF)
    {
        leaf=maxdep=maxson=0 ;
        now=0 ;
        dfs(1) ;
        printf("%d %d %d\n",leaf,maxdep,maxson) ;
    }
}
