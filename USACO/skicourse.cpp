#include<bits/stdc++.h>
#define MIN(x,y,z) min(min(x,y),z)
using namespace std;
const int maxn=100+10 ;

int dp[maxn][maxn] ;
int tmp[2*maxn*maxn] ;
int n,m,G[maxn][maxn],G2[maxn][maxn] ;
bool used[maxn][maxn] ;

void cover(int x,int y,int d)
{
    used[x][y]=1 ;
    for(int i=x-d+1;i<=x;i++) for(int j=y-d+1;j<=y;j++)
        G[i][j]=3 ;
}

bool check(int d)
{
    memset(used,0,sizeof(used)) ;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
        G[i][j]=G2[i][j] ;
    while(1)
    {
        int cnt=0 ;
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
        {
            dp[i][j]=1 ;
            if(i==1 || j==1) continue ;
            int t=G[i][j] ;
            if(((t&G[i-1][j])!=0)&&((t&G[i][j-1])!=0)
                &&((t&G[i-1][j-1])!=0))
                dp[i][j]=MIN(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])+1 ;
            if(dp[i][j]>=d && !used[i][j])
                tmp[cnt++]=i , tmp[cnt++]=j ;
        }
        if(!cnt) break ;
        for(int i=0;i<cnt;i+=2) cover(tmp[i],tmp[i+1],d) ;
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
        if(G[i][j]!=3) return 0 ;
    return 1 ;
}

main()
{
//    freopen("skicourse.in","r",stdin) ;
//    freopen("skicourse.out","w",stdout) ;
    scanf("%d%d",&n,&m) ;
    for(int i=1;i<=n;i++)
    {
        char s[maxn] ; scanf("%s",s+1) ;
        for(int j=1;j<=m;j++)
            G[i][j]=G2[i][j]=(s[j]=='R' ? 1 : 2) ;
    }

    int l=1 , r=min(m,n)+1 ;
    while(r-l>1)
    {
        int mid=(r+l)/2 ;
        if(check(mid)) l=mid ;
        else r=mid ;
    }
    printf("%d\n",l) ;
}
