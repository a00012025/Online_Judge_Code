#include<bits/stdc++.h>
#define INF 10000000
using namespace std;
const int maxn=1000+50 ;

int sz[maxn],dp[2][maxn][maxn] ;
int dp2[maxn][maxn] ;
vector<int> v[maxn] ;
bool G[maxn] ;

void dfs(int x,int fa)
{
    sz[x]=1 ;
    if(x && (int)v[x].size()==1)
    {
        if(!G[x]) dp[0][x][0]=1 , dp[1][x][0]=0 ;
        else dp[0][x][0]=-INF , dp[1][x][0]=0 ;
        return ;
    }
    for(auto i : v[x]) if(i!=fa)
        dfs(i,x) , sz[x]+=sz[i] ;
    for(int b=0;b<2;b++)
    {
        if(b==0 && G[x])
        {
            for(int i=0;i<sz[x];i++) dp[b][x][i]=-INF ;
            continue ;
        }
        for(int i=0;i<sz[x];i++) dp2[0][i]=-INF ;
        dp2[0][0]=0 ;
        int tot=0,cnt=0 ;
        for(int i=0;i<v[x].size();i++) if(v[x][i]!=fa)
        {
            int y=v[x][i] ;
            tot+=sz[y] ;
            for(int j=0;j<sz[x];j++) dp2[cnt+1][j]=-INF ;

            for(int j=(b!=0);j<=tot;j++)
                for(int k=0;k<sz[y] && j-k-(b!=0)>=0;k++)
                dp2[cnt+1][j]=max(dp2[cnt+1][j],
                        dp2[cnt][j-k-(b!=0)]+dp[0][y][k]) ;

            for(int j=(b!=1);j<=tot;j++)
                for(int k=0;k<sz[y] && j-k-(b!=1)>=0;k++)
                dp2[cnt+1][j]=max(dp2[cnt+1][j],
                        dp2[cnt][j-k-(b!=1)]+dp[1][y][k]) ;
            cnt++ ;
        }
        for(int i=0;i<sz[x];i++)
            dp[b][x][i]= (b==0) + dp2[cnt][i] ;
    }
}

main()
{
    int n,k,num ;
    scanf("%d%d%d",&n,&k,&num) ;
    if(k+num>n) { printf("ACM rules!\n") ; return 0 ; }
    while(num--)
    {
        int x ; scanf("%d",&x) ;
        G[x]=1 ;
    }
    for(int i=1;i<n;i++)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        v[x].push_back(y) ;
        v[y].push_back(x) ;
    }

    dfs(0,-1) ;

    int ans1=n-1,ans2=n-1 ;
    for(int i=0;i<n;i++) if(dp[0][0][i]>=k)
        { ans1=i ; break ; }
    for(int i=0;i<n;i++) if(dp[1][0][i]>=k)
        { ans2=i ; break ; }
    printf("%d\n",min(ans1,ans2)) ;
}
