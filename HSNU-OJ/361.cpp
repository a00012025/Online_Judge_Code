#include<bits/stdc++.h>
#define LL long long
const int maxn=400000+10 ;
struct P{int id,val ;} a[maxn],b[maxn];
int left[maxn],right[maxn] ;

void mer(int l,int r)
{
    if(l==r) return ;
    int mid=(l+r)/2 ;
    mer(l,mid) ; mer(mid+1,r) ;
    int i1=l,i2=l , j1=mid+1,j2=mid+1 , cnt=l ;
    while(i2<=mid || j2<=r)
    {
        if(i2==mid+1 || (j2!=r+1 && a[j2].val<a[i2].val))
        {
            while(i1<=mid && a[i1].val<=a[j2].val) i1++ ;
            left[a[j2].id]+=mid-i1+1 ;
            b[cnt++]=a[j2++] ;
        }
        else
        {
            while(j1<=r && a[j1].val<=a[i2].val) j1++ ;
            right[a[i2].id]+=r-j1+1 ;
            b[cnt++]=a[i2++] ;
        }
    }
    for(int i=l;i<=r;i++) a[i]=b[i] ;
}

main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++) { scanf("%d",&a[i].val) ; a[i].id=i ; }

    memset(left,0,sizeof(left)) ;
    memset(right,0,sizeof(right)) ;
    mer(1,n) ;
    LL ans=0LL ;
    for(int i=1;i<=n;i++) ans+=std::min(left[i],right[i]) ;
    printf("%lld\n",ans) ;
}
