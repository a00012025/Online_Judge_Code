#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=1000000+10 ;
struct P
{
    LL val ;
    int pos ;
    bool operator < (const P &rhs) const
    {
        if(val!=rhs.val) return val<rhs.val ;
        else return pos<rhs.pos ;
    }
};

int a[maxn] ;
LL sum[maxn] ;
P dp[maxn] ;
main()
{
    int n,Q ; scanf("%d%d",&n,&Q) ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
    while(Q--)
    {
        int k ; scanf("%d",&k) ;
        sum[0]=0LL ;
        for(int i=1;i<=n;i++) sum[i]=(LL)sum[i-1]+a[i]-k ;
        int num=0 , ans=0 ;
        for(int i=n;i>=0;i--)
        {
            if(i==n || sum[i]>dp[num-1].val)
                { dp[num++]=(P){sum[i],i} ; continue ; }
            int id=lower_bound(dp,dp+num,(P){sum[i],-1}) - dp ;
            ans=max(ans,dp[id].pos-i) ;
        }
        printf("%d%c",ans,Q?' ':'\n') ;
    }
}
