#include<stdio.h>
#define LL long long
LL ma(LL x,LL y)
{
    if(x>y) return x ;
    else return y ;
}
main()
{
    LL n,m,M=0,a[100001],b[100001] ;
    scanf("%I64d %I64d",&n,&m) ;
    for(int i=1;i<=n;i++) {scanf("%I64d",&a[i]) ; M=ma(M,a[i]) ;}
    for(int i=1;i<=n;i++) scanf("%I64d",&b[i]) ;
    LL l=1,r=M ;
    while(r-l>1)
    {
        LL k=0,mid=(r+l)/2 ;
        for(int i=1;i<=n;i++)
        {
            if(a[i]>=mid) k+=1+((a[i]-mid)/b[i]) ;
        }
        if(k<m) r=mid ;
        else l=mid ;
    }
    if(l==M-1)
    {
        LL k=0 ;
        for(int i=1;i<=n;i++)
        {
            if(a[i]>=M) k+=1+((a[i]-M)/b[i]) ;
        }
        if(k>=m) l=M ;
    }
    LL k=0,ans=0 ;
    for(int i=1;i<=n;i++) if(a[i]>=l)
    {
        LL ter=1+((a[i]-l)/b[i]) ;
        k+=ter ;
        ans+=(ter*(2*a[i]-(ter-1)*b[i]))/2 ;
    }
    printf("%I64d\n",ans-l*(k-m)) ;
}
