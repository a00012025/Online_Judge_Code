#include<bits/stdc++.h>
#define INF 10000000
using namespace std;
int G[251][251],sum[251][251] ;
int n,m,k ;

inline int get_sum(int x1,int y1,int x2,int y2)
{
    return sum[x2][y2]-sum[x2][y1-1]-sum[x1-1][y2]+sum[x1-1][y1-1] ;
}

int cal1(int L,int R) /// (L,1),(L,m),(R,1),(R,m) ;
{
    if(get_sum(L,1,R,m)<k) return INF ;
    int ret=INF ;
    int j=0 , now=0 ;
    for(int i=1;i<=m;i++)
    {
        while(j<m && now<k) j++ , now+=get_sum(L,j,R,j) ;
        if(now==k) ret=min(ret,2*(j-i+1 + R-L+1)) ;
        now-=get_sum(L,i,R,i) ;
    }
    return ret ;
}

int cal2(int L,int R) /// (1,L),(1,R),(n,L),(n,R)
{
    if(get_sum(1,L,n,R)<k) return INF ;
    int ret=INF ;
    int j=0 , now=0 ;
    for(int i=1;i<=n;i++)
    {
        while(j<n && now<k) j++ , now+=get_sum(j,L,j,R) ;
        if(now==k) ret=min(ret,2*(j-i+1 + R-L+1)) ;
        now-=get_sum(i,L,i,R) ;
    }
    return ret ;
}

int ans[5][300] ;
main()
{
    int num ; scanf("%d%d%d%d",&n,&m,&num,&k) ;
    while(num--)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        G[x][y]++ ;
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
        sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+G[i][j] ;

    ans[1][0]=INF ;
    for(int i=1;i<=n;i++)
    {
        ans[1][i]=ans[1][i-1] ;
        for(int j=1;j<=i;j++) ans[1][i]=min(ans[1][i],cal1(j,i)) ;
    }

    ans[2][n+1]=INF ;
    for(int i=n;i>=1;i--)
    {
        ans[2][i]=ans[2][i+1] ;
        for(int j=i;j<=n;j++) ans[2][i]=min(ans[2][i],cal1(i,j)) ;
    }

    ans[3][0]=INF ;
    for(int i=1;i<=m;i++)
    {
        ans[3][i]=ans[3][i-1] ;
        for(int j=1;j<=i;j++) ans[3][i]=min(ans[3][i],cal2(j,i)) ;
    }

    ans[4][m+1]=INF ;
    for(int i=m;i>=1;i--)
    {
        ans[4][i]=ans[4][i+1] ;
        for(int j=i;j<=m;j++) ans[4][i]=min(ans[4][i],cal2(i,j)) ;
    }

    int ANS=INF ;
    for(int i=1;i<n;i++) ANS=min(ANS,ans[1][i]+ans[2][i+1]) ;
    for(int i=1;i<m;i++) ANS=min(ANS,ans[3][i]+ans[4][i+1]) ;
    if(ANS==INF) printf("NO\n") ;
    else printf("%d\n",ANS) ;
}
