#include<bits/stdc++.h>
using namespace std;

int cnt,n,k,goal[20],now[20] ;
bool ok ;

bool check()
{
    for(int i=1;i<=k;i++) if(goal[i]!=now[i]) return 0 ;
    return 1 ;
}

bool dfs(int last,int x)
{
    if(x==k)
    {
        if(ok)
        {
            for(int i=1;i<=k;i++)printf("%d%c",now[i],i==k?'\n':' ') ;
            return 1 ;
        }
        cnt++ ;
        if(check()) {ok=1 ; printf("%d\n",cnt) ; }
        return 0 ;
    }
    for(int i=last+1;i<=n;i++)
    {
        now[x+1]=i ;
        if(dfs(i,x+1)) return 1 ;
    }
    return 0 ;
}

main()
{
    scanf("%d%d",&n,&k) ;
    for(int i=1;i<=k;i++) scanf("%d",&goal[i]) ;
    ok=0 ; cnt=0 ;
    if(!dfs(0,0)) printf("no next combination\n") ;
}
