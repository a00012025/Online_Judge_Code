#include<stdio.h>
int a[1000001],b[1000001] ;

void mer(int l,int r)
{
    if(l==r) return ;
    int mid=(l+r)/2 ;
    mer(l,mid) ; mer(mid+1,r) ;
    int cnt1=l,cnt2=mid+1 ;
    for(int cnt=1;cnt<=r-l+1;cnt++)
    {
        if(cnt2==r+1 || (cnt1<=mid && a[cnt1]<=a[cnt2]))
            {b[cnt]=a[cnt1] ; cnt1++ ; }
        else if(cnt1==mid+1 || (cnt2<=r && a[cnt2]<=a[cnt1]))
            {b[cnt]=a[cnt2] ; cnt2++ ; }
    }
    for(int i=1;i<=r-l+1;i++) a[l-1+i]=b[i] ;
}

main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
        mer(1,n) ;
        for(int i=1;i<=n;i++) printf("%d ",a[i]) ;
        printf("\n") ;
    }
}
