#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int d[100][100][100][2],n,pos[100],c[100] ;
int vis[100][100][100][2],tc=0 ;

int dp(int i,int j,int k,int tp)
{
    if(vis[i][j][k][tp]==tc) return d[i][j][k][tp] ;
    if(k==0) return 0 ;
    vis[i][j][k][tp]=tc ;
    int &ans=d[i][j][k][tp] ;
    ans=0 ;

    if(tp==0)
    {
        for(int p=0;p<i;p++)
            ans=max(ans, c[p] - k*abs(pos[p]-pos[i]) + dp(p,j,k-1,0)) ;
        for(int p=j+1;p<n;p++)
            ans=max(ans, c[p] - k*abs(pos[p]-pos[i]) + dp(i,p,k-1,1)) ;
    }
    else
    {
        for(int p=0;p<i;p++)
            ans=max(ans, c[p] - k*abs(pos[p]-pos[j]) + dp(p,j,k-1,0)) ;
        for(int p=j+1;p<n;p++)
            ans=max(ans, c[p] - k*abs(pos[p]-pos[j]) + dp(i,p,k-1,1)) ;
    }

    return ans ;
}

main()
{
    int T ;
    scanf("%d",&T) ;
    memset(vis,0,sizeof(vis)) ;
    while(T--)
    {
        scanf("%d",&n) ;
        tc++ ;
        for(int i=0;i<n;i++) scanf("%d",&pos[i]) ;
        for(int i=0;i<n;i++) scanf("%d",&c[i]) ;
        int ans=0 ;
        for(int i=0;i<n;i++) for(int k=1;k<=n;k++)
            ans=max(ans,c[i]-k*abs(pos[i])+dp(i,i,k-1,0)) ;
        printf("%d\n",ans) ;
    }
}
