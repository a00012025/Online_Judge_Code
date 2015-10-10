#include<bits/stdc++.h>
#define DB double
using namespace std;
const int maxn=6561,maxt=240+5 ;

inline void decode(int x,int *a)
{
    for(int i=0;i<8;i++) a[i]=x%3 , x/=3 ;
}

int encode(int *a)
{
    int ret=0 ;
    for(int i=7;i>=0;i--) ret=ret*3+a[i] ;
    return ret ;
}

DB dp[maxn][maxt] ;
DB p[8] ;
int c[8],d[8] ;
DB DP(int S,int nowt)
{
    if(nowt>240) return -1e7 ;
    if(dp[S][nowt]>=0) return dp[S][nowt] ;
    DB &ans=dp[S][nowt] ; ans=0.0 ;
    int cnt=0,num=0 ;
    int tmp[8] ; decode(S,tmp) ;

    for(int i=0;i<8;i++)
    {
        if(tmp[i]==2) num++ ;
        else if(tmp[i]==1 && d[i]+nowt<=240)
        {
            cnt++ ; tmp[i]++ ;
            ans=max(ans,DP(encode(tmp),d[i]+nowt)) ;
            tmp[i]-- ;
        }
        else if(tmp[i]==0 && c[i]+nowt<=240)
        {
            cnt++ ; tmp[i]++ ;
            DB val=(1-p[i])*DP(encode(tmp),c[i]+nowt) ;
            tmp[i]++ ;
            val+=p[i]*DP(encode(tmp),c[i]+nowt) ;
            ans=max(ans,val) ; tmp[i]-=2 ;
        }
    }
    return ans=max(ans,num*1.0) ;
}

main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        for(int i=0;i<8;i++) scanf("%d%lf%d",&c[i],&p[i],&d[i]) ;
        fill(dp[0],dp[maxn-1]+maxt,-1) ;
        printf("%.15f\n",DP(0,0)) ;
    }
}
