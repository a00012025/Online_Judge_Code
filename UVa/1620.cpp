#include<stdio.h>
int n,a[1000],b[1000],inv ;

void mer(int l,int r)
{
    if(l==r) return ;
    int mid=(l+r)/2 ;
    mer(l,mid) ; mer(mid+1,r) ;
    int i=l , j=mid+1 , cnt=l ;
    while(i<=mid || j<=r)
    {
        if(i==mid+1 || (j!=r+1 && a[j]<a[i]))
            {b[cnt++]=a[j++] ; inv += mid+1-i ;}
        else b[cnt++]=a[i++] ;
    }
    for(int i=l;i<=r;i++) a[i]=b[i] ;
}

int inv_num()
{
    inv=0 ;
    mer(1,n) ;
    return inv ;
}

main()
{
    int T;
    scanf("%d",&T) ;
    while(T--)
    {
        scanf("%d",&n) ;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
        if(n%2==0) printf("possible") ;
        else if(inv_num()%2==0) printf("possible") ;
        else printf("impossible") ;
        printf("\n") ;
    }
}
