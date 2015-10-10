#include<stdio.h>
#include<string.h>
int a,b,goal ,ans[100000];
bool vis[1001][1001] ;

bool dfs(int x,int y,int num)
{
    if(y==goal)
    {
        for(int i=0;i<=num;i++)
        {
            if(ans[i]==1) printf("fill A\n") ;
            if(ans[i]==2) printf("fill B\n") ;
            if(ans[i]==3) printf("empty A\n") ;
            if(ans[i]==4) printf("empty B\n") ;
            if(ans[i]==5) printf("pour A B\n") ;
            if(ans[i]==6) printf("pour B A\n") ;
        }
        return true ;
    }
    vis[x][y]=1 ;
    if(x!=a)
    {
        ans[num+1]=1 ;
        if(!vis[a][y] && dfs(a,y,num+1)) return true ;
    }
    if(y!=b)
    {
        ans[num+1]=2 ;
        if(!vis[x][b] && dfs(x,b,num+1)) return true ;
    }
    if(x!=0)
    {
        ans[num+1]=3 ;
        if(!vis[0][y] && dfs(0,y,num+1)) return true ;
    }
    if(y!=0)
    {
        ans[num+1]=4 ;
        if(!vis[x][0] && dfs(x,0,num+1)) return true ;
    }
    if(y!=b && x!=0)
    {
        ans[num+1]=5 ;
        if(x+y>b)
        {
            if(!vis[x+y-b][b] && dfs(x+y-b,b,num+1)) return true ;
        }
        else
        {
            if(!vis[0][x+y] && dfs(0,x+y,num+1)) return true ;
        }
    }
    if(x!=a && y!=0)
    {
        ans[num+1]=6 ;
        if(x+y>a)
        {
            if(!vis[a][x+y-a] && dfs(a,x+y-a,num+1)) return true ;
        }
        else
        {
            if(!vis[0][x+y] && dfs(0,x+y,num+1)) return true ;
        }
    }
    //vis[x][y]=0 ;
    return false ;
}

main()
{
    while(scanf("%d%d%d",&a,&b,&goal)!=EOF)
    {
        memset(vis,0,sizeof(vis)) ;
        dfs(0,0,-1) ;
        printf("success\n") ;
    }
}
