#include<stdio.h>
int t,n,a[13],ans[13] ;
bool found ;

void dfs(int last,int sum,int num)
{
    bool vis[101]={0} ;
    if(sum==t)
    {
        for(int i=1;i<=num;i++) printf("%d%c",a[ans[i]],i==num?'\n':'+') ;
        found=1 ;
        return ;
    }
    for(int i=last+1;i<=n;i++) if(a[i]+sum<=t)
    {
        if(vis[a[i]]) continue ;
        ans[num+1]=i ;
        dfs(i,sum+a[i],num+1) ;
        vis[a[i]]=1 ;
    }
}

main()
{
    while(scanf("%d %d",&t,&n)==2 && t+n)
    {
        for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
        found=0 ;
        printf("Sums of %d:\n",t) ;
        dfs(0,0,0) ;
        if(!found) printf("NONE\n") ;
    }
}
