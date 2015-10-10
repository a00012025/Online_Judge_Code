#include<stdio.h>
#include<string.h>
bool vis[200][200] ;
int N;
unsigned long long ans[51] ;
void dfs(int x,int y,int n)
{
 if(n==0) ans[N]+=1 ;
 else
 	{
 	if(vis[x+1][y]==0)
 		{
 		vis[x+1][y]=1 ;
 		dfs(x+1,y,n-1) ; 
 		vis[x+1][y]=0 ;
 		}
 	if(vis[x-1][y]==0)
 		{
 		vis[x-1][y]=1 ;
 		dfs(x-1,y,n-1) ; 
 		vis[x-1][y]=0 ;
 		}
 	if(vis[x][y+1]==0)
 		{
 		ans[N]+=ans[n-1] ;
 		}
 	}
}
main()
{
 int n;
 memset(vis,0,sizeof(vis)) ;
 for(n=1;n<=50;n++){
 N=n ; ans[0]=1 ;
 vis[50][0]=1 ;
 ans[N]=0 ;
 dfs(50,0,n) ;
 }
 while(scanf("%d",&n)==1) printf("%llu\n",ans[n]) ;
}
