#include<bits/stdc++.h>
#define LL long long
#define INF (1LL<<60)
using namespace std;
const int maxn=100000+10 ;
int a[maxn],b[maxn] ;
LL S=0LL,cnt[maxn] ;
main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++)
        scanf("%d%d",&a[i],&b[i]) , cnt[a[i]]++ , S+=b[i] ;
    for(int i=maxn-2;i>=0;i--) cnt[i]+=cnt[i+1] ;
    for(int i=maxn-2;i>=0;i--) cnt[i]+=cnt[i+1] ;
    int lo=0 ;
    for(int i=1;i<=n;i++) lo=max(lo,a[i]-b[i]+1) ;

    LL sqsum=0LL , ans=INF ;
    for(int i=maxn-2;i>=lo;i--)
    {
        sqsum+=(cnt[i+1]-cnt[i])*(cnt[i+1]-cnt[i]) ;
        if(!cnt[i-1]) continue ;
        if(i==1) { ans=sqsum ; break ; }
        LL val=S-cnt[i] ;
        if(val<0) break ;
        LL q=val/(i-1) , r=val-q*(i-1) ;
        if(cnt[i-1]-cnt[i]<q || (r && cnt[r]-cnt[r+1]<q+1)) continue ;
        ans=min(ans,sqsum+(i-1-r)*q*q+r*(q+1)*(q+1)) ;
    }
    printf("%I64d\n",(ans-S)/2) ;
}
