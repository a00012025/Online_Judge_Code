#include<stdio.h>
#include<string.h>
bool p[40]={0},vis[20] ;
int ans[20],n ;

void dfs(int x)
{
    if(x==n)
    {
        if(p[ans[n]+ans[1]])
        {
            for(int i=1;i<n;i++) printf("%d ",ans[i]) ;
            printf("%d\n",ans[n]) ;
        }
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i] || !p[i+ans[x]]) continue ;
        ans[x+1]=i ; vis[i]=1 ;
        dfs(x+1) ; vis[i]=0 ;
    }
}

main()
{
        //freopen("1.txt","r",stdin) ;
        //freopen("2.txt","w",stdout) ;

    p[2]=1 ; p[3]=1 ; p[5]=1 ; p[7]=1 ;
    p[11]=1 ; p[13]=1 ; p[17]=1 ; p[19]=1 ;
    p[23]=1 ; p[29]=1 ; p[31]=1 ; p[37]=1 ;
    int tc=0,st=1;
    while(scanf("%d",&n)!=EOF)
    {
        if(st) st=0 ;
        else printf("\n") ;
        memset(vis,0,sizeof(vis)) ;
        printf("Case %d:\n",++tc) ;
        ans[1]=1 ; vis[1]=1 ;
        dfs(1) ;
    }

}
