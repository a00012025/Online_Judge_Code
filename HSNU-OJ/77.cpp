#include<bits/stdc++.h>
using namespace std;

int now[20],m ;
inline void decode(int val)
{
    for(int i=0;i<m;i++)
        now[i]=val%3 , val/=3 ;
}

inline int encode()
{
    int ret=0 ;
    for(int i=0;i<m;i++) ret=ret*3+now[i] ;
    return ret ;
}

int dp[2][60000] ;
char G[101][11] ;
vector<int> tmp ;
main()
{
    int n ; scanf("%d%d",&n,&m) ;
    for(int i=0;i<n;i++) scanf("%s",G[i]) ;
    int M=1 ; for(int i=1;i<=m;i++) M*=3 ;
    for(int i=0;i<n;i++) for(int j=0;j<M;j++)
    {
        if(j==0) memset(dp[(i+1)%2],0,sizeof(dp[(i+1)%2])) ;
        decode(j) ;

        for(int k=0;k<m;k++)
        {
            if(now[k]==2 && (i<2 || G[i-2][k]=='H'))
                continue ;
            if(now[k]==1 && (i<1 || G[i-1][k]=='H'))
                continue ;
        }
        tmp.clear() ;
        for(int k=0;k<m;k++) if(!now[k] && G[i][k]=='P')
            tmp.push_back(k) ;
        for(int k=0;k<m;k++)
        {
            if(now[k]==2) now[k]=0 ;
            else if(now[k]==1) now[k]=2 ;
        }
        int &x=dp[(i+1)%2][encode()] ; x=max(x,dp[i%2][j]) ;
        for(int k=0;k<tmp.size();k++)
        {
            now[tmp[k]]=1 ;
            int &y=dp[(i+1)%2][encode()] ;
            y=max(y,dp[i%2][j]+1) ;
            now[tmp[k]]=0 ;
        }
/*
        for(int k=0;k<tmp.size();k++) for(int l=k+1;l<tmp.size();l++)
            if(tmp[l]>tmp[k]+2)
        {
            now[tmp[l]]=now[tmp[k]]=1 ;
            int &y=dp[(i+1)%2][encode()] ;
            y=max(y,dp[i%2][j]+2) ;
            now[tmp[l]]=now[tmp[k]]=0 ;
        }
*/
    }

    int ans=0 ;
    for(int i=0;i<M;i++) ans=max(ans,dp[n%2][i]) ;
    printf("%d\n",ans) ;
}
