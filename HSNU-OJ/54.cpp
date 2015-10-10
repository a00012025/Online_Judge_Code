#include<bits/stdc++.h>
using namespace std;
bool G[5001][5001] ;
int n,m,x[5001],y[5001] ;

int check(int i,int j)
{
    int dx=x[j]-x[i] , dy=y[j]-y[i] , nx=x[j] , ny=y[j] ;
    int ret=1 ;
    while(1<=nx && nx<=n && 1<=ny && ny<=m)
    {
        if(!G[nx][ny]) return 0 ;
        ret++ ; nx+=dx ; ny+=dy ;
    }
    return ret==2 ? 0 : ret ;
}

main()
{
        //freopen("frog.16.in","r",stdin) ;
    int k ; scanf("%d%d%d",&n,&m,&k) ;
    for(int i=1;i<=k;i++) {scanf("%d%d",&x[i],&y[i]) ; G[x[i]][y[i]]=1 ; }
    int ans=0 ;
    for(int i=1;i<=k;i++) for(int j=1;j<=k;j++) if(i!=j)
    {
        int p=x[i]+(x[j]-x[i])*(ans-1),q=y[i]+(y[j]-y[i])*(ans-1) ;
        int r=2*x[i]-x[j] , s=2*y[i]-y[j] ;
        if(1<=r && r<=n && 1<=s && s<=m) continue ;
        if(ans && (p<1 || p>n || q<1 || q>m )) continue ;
        ans=max(ans,check(i,j)) ;
    }
    printf("%d\n",ans) ;
}
