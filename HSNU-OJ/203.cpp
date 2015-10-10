#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=100000+10 ;

int h[maxn],w[maxn] ;
LL sum[maxn],dp[maxn] ;
int deq[maxn];
multiset<LL> mst ;

main()
{
    int n,L ; scanf("%d%d",&n,&L) ;
    for(int i=1;i<=n;i++) scanf("%d%d",&h[i],&w[i]) ;
    int l=0 , r=0 ;
    deq[r++]=0 ;
    for(int i=1;i<=n;i++)
    {
        sum[i]=sum[i-1]+w[i] ;
        while(r>l+1 && h[deq[r-1]]<=h[i])
            mst.erase(mst.find(dp[deq[r-2]]+h[deq[r-1]])) , r-- ;
        mst.insert(dp[deq[r-1]]+h[i]) ;
        deq[r++]=i ;

        while(sum[i]-sum[deq[l]]>L)
        {
            mst.erase(mst.find(dp[deq[l]]+h[deq[l+1]])) ;
            if(++deq[l] == deq[l+1]) l++ ;
            else mst.insert(dp[deq[l]]+h[deq[l+1]]) ;
        }
        dp[i]=*mst.begin() ;
    }
    printf("%I64d\n",dp[n]) ;
}
