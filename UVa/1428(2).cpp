#include<stdio.h>
#include<string.h>
#define LL long long
struct P {int val,id;};
P a[20001],b[20001] ;
int left[20001],right[20001],pos[20001] ;

void mer(int l,int r)
{
    if(l==r) return ;
    int mid=(l+r)/2 ;
    mer(l,mid) ; mer(mid+1,r) ;
    int i=l , j=mid+1 , cnt=l ;
    while(i<=mid || j<=r)
    {
        if(i==mid+1 || (j!=r+1 && a[j].val<a[i].val))
        {
            b[cnt].val=a[j].val ; b[cnt].id=a[j].id ;
            left[a[j].id] += i-l ;
            cnt++ ; j++ ;
        }
        else
        {
            b[cnt].val=a[i].val ; b[cnt].id=a[i].id ;
            cnt++ ; i++ ;
        }
    }
    for(int i=l;i<=r;i++) {a[i].val=b[i].val ; a[i].id=b[i].id ;}
}

main()
{
    int T;
    scanf("%d",&T) ;
    while(T--)
    {
        int n;
        scanf("%d",&n) ;
        for(int i=1;i<=n;i++) {scanf("%d",&a[i].val) ; a[i].id=i ;}
        memset(left,0,sizeof(left)) ;
        mer(1,n) ;
        for(int i=1;i<=n;i++) pos[a[i].id]=i ;
        for(int i=1;i<=n;i++) right[i]=pos[i]-1-left[i] ;
        LL ans=0 ;
        for(int i=2;i<n;i++) ans+=left[i]*(n-i-right[i])+right[i]*(i-1-left[i]) ;
        printf("%lld\n",ans) ;
    }
}
