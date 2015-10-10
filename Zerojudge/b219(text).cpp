#include<stdio.h>
#include<string.h>
int cnt ;
bool vis[200] ;

void dfs(int num,int last,int n)
{
    if(num==n) { cnt++ ; return ; }
    for(int i=1;i<=n;i++) if(!vis[i] && i!=last+1)
    {
        vis[i]=1 ;
        dfs(num+1,i,n) ;
        vis[i]=0 ;
    }
}

main()
{
    for(int i=1;i<=20;i++)
    {
        cnt=0 ;
        memset(vis,0,sizeof(vis)) ;
        dfs(0,-1,i) ;
        printf("ans %d = %d\n",i,cnt) ;
    }
}
