#include<stdio.h>
#include<string.h>
int a[1000001],ans[1000001],m,n,nowl,visnum ;
bool vis[1000001],yes,fin ;

void dfs(int x)
{
    if(fin) return ;
    if(x==m)
    {
        if(!yes) return ;
        for(int i=1;i<=m;i++) printf("%d ",ans[i]) ;
        printf("\n") ;
        fin=1 ; return ;
    }
    if(yes==0)
    {
        int num ;
        for(num=a[x+1];(num<=n) && (vis[num]==1);num++) ;
        for(int i=num;i<=n;i++)
        {
            if(vis[i]) continue ;
            ans[x+1]=i ; vis[i]=1 ;
            if(i!=a[x+1]) yes=1 ;
            dfs(x+1) ;
            vis[i]=0 ; yes=0 ;
            if(fin) return ;
        }
    }
    else if(yes==1)
    {
        for(int i=1;i<=x;i++) printf("%d ",ans[i]) ;
        int now=1 ;
        for(int i=x+1;i<=m;i++)
        {
            for(;vis[now]==1;now++) ;
            printf("%d ",now) ;
            vis[now]=1 ;
        }
        printf("\n") ;
        fin=1 ; return ;
    }
}

main()
{
    int T;
    scanf("%d",&T) ;
    while(T--)
    {
        scanf("%d %d",&m,&n) ;
        memset(vis,0,sizeof(vis)) ;
        for(int i=1;i<=m;i++) scanf("%d",&a[i]) ;
        yes=0 ; fin=0 ;
        nowl=1 ; visnum=0 ;
        dfs(0) ;
    }
}
