#include<stdio.h>
int n,p,fb[21][21],now[21],ans ;
int len[21] ;

bool check(int x) // now[1]~now[n]
{
    for(int i=1;i<=p;i++)
    {
        int l=len[i] ;
        if(l>x) continue ;
        for(int j=1;j<=x-l+1;j++)
        {
            int dif=0 ;
            for(int k=1;k<=l;k++) if(now[j-1+k]!=fb[i][k])
                {dif=1 ; break ;}
            if(dif) continue ;
            else return false ;
        }
    }
    return true ;
}

void dfs(int x)
{
    if(x>=2 && check(x)) ans++ ;
    for(int i=now[x]+1;i<=n;i++)
    {
        now[x+1]=i ;
        dfs(x+1) ;
    }
}

main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&n,&p) ;
        for(int i=1;i<=p;i++)
        {
            int num ;
            scanf("%d",&num) ;
            for(int j=1;j<=num;j++) scanf("%d",&fb[i][j]) ;
            len[i]=num ;
        }
        ans=0 ; now[0]=0 ;
        dfs(0) ;
        if(!ans) printf("so sad\n") ;
        else printf("%d\n",ans) ;
    }
}
