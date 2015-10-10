#include<bits/stdc++.h>
using namespace std;

int dp[101][70][70] ;
char G[101][20] ;
vector<int> st[101] ;
int num[101][70] ;
main()
{
    int n,m ; scanf("%d%d",&n,&m) ;
    for(int i=0;i<n;i++) scanf("%s",G[i]) ;
    for(int i=0;i<n;i++)
    {
        int S0=0 ;
        for(int j=0;j<m;j++) if(G[i][j]=='P')
            S0+=(1<<j) ;
        for(int S=S0;;S=((S-1)&S0))
        {
            bool ok=1 ;
            for(int j=0;j<m-1;j++) if(S&(1<<j))
            {
                if(S&(1<<(j+1))) { ok=0 ; break ; }
                if(S&(1<<(j+2))) { ok=0 ; break ; }
            }
            if(!ok) continue ;
            st[i].push_back(S) ;
            int &num2=num[i][st[i].size()-1] ; num2=0 ;
            for(int j=0;j<m;j++) if(S&(1<<j)) num2++ ;
            if(S==0) break ;
        }
    }

    memset(dp,-1,sizeof(dp)) ;
    for(int i=0;i<st[0].size();i++) for(int j=0;j<st[1].size();j++)
    {
        if(st[0][i]&st[1][j]) continue ;
        dp[1][i][j]=num[0][i]+num[1][j] ;
    }

    for(int i=1;i<n-1;i++) for(int j=0;j<st[i-1].size();j++)
        for(int k=0;k<st[i].size();k++) if(dp[i][j][k]!=-1)
    {
        int val=st[i-1][j]+st[i][k] ;
        for(int z=0;z<st[i+1].size();z++) if(!(val&st[i+1][z]))
            dp[i+1][k][z]=max(dp[i+1][k][z],dp[i][j][k]+num[i+1][z]) ;
    }

    int ans=0 ;
    for(int i=0;i<st[n-2].size();i++) for(int j=0;j<st[n-1].size();j++)
        ans=max(ans,dp[n-1][i][j]) ;
    printf("%d\n",ans) ;
}
