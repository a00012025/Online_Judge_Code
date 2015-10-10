#include<bits/stdc++.h>
using namespace std;

int now[10],used[10],n ;
char s[10] ;

void dfs(int x)
{
    if(x==n)
    {
        for(int i=0;i<n;i++) printf("%c",s[now[i]]) ;
        printf("\n") ;
        return ;
    }
    for(int i=0;i<n;i++) if(!used[i])
    {
        used[i]=1 ;
        now[x]=i ;
        dfs(x+1) ;
        used[i]=0 ;
    }
}

main()
{
    bool fir=1 ;
    while(scanf("%s",s)!=EOF)
    {
        n=strlen(s) ;
        sort(s,s+n) ;
        memset(used,0,sizeof(used)) ;
        if(fir) fir=0 ;
        else printf("\n") ;
        dfs(0) ;
    }
}
