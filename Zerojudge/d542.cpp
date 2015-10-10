#include<stdio.h>
#define LL long long
int a[501000],b[501000] ;
LL ans=0 ;

void mer(int l,int r)
{
    if(l==r) return ;
    int mid=(l+r)/2 ;
    mer(l,mid) ; mer(mid+1,r) ;
    int p=l , q=mid+1 , cnt=0 ;
    while(p!=mid+1 || q!=r+1)
    {
            //printf("%d,%d\n",p,q);
        if((p==mid+1) || (q<=r && a[q]<a[p]))
        {
            b[cnt++]=a[q++] ;
            ans+=(LL)mid-p+1 ;
        }
        else b[cnt++]=a[p++] ;
    }
    for(int i=0;i<=r-l;i++) a[i+l]=b[i] ;
}

main()
{
    int n;
    while(scanf("%d",&n) && n)
    {
        for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
        ans=0 ;
        mer(1,n) ;
        printf("%lld\n",ans) ;
    }
}
