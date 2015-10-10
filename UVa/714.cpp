#include<stdio.h>
#include<stdlib.h>
#define LL long long
int n ;
LL ans,a[1000] ;

int check(int l,int r,LL S)
{
    LL sum=0LL ;
    int cnt=0 ;
    for(int i=l;i<=r;i++)
    {
        if(a[i]>S) return 2000000000;
        if(sum+a[i]>S)
        {
            cnt++ ; sum=a[i] ;
        }
        else sum+=a[i] ;
    }
    cnt++ ;
    return cnt ;
}

main()
{
        //freopen("1.txt","r",stdin) ;
        //freopen("2.txt","w",stdout) ;

    int T ;scanf("%d",&T) ;
    while(T--)
    {
        int m ;
        scanf("%d%d",&n,&m) ;
        LL l=0 , r=0 ;
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&a[i]) ;
            r+=a[i] ;
        }
        while(r-l>1)
        {
            int mid=(r+l)/2 ;
            if(check(1,n,mid)<=m) r=mid ;
            else l=mid ;
        }
        ans=r ;
        int num=m , i ;
            //for(int i=1;i<=n;i++) printf("%d,",check(i,n,ans)) ;
            //printf("\n") ;
        for(i=1;i<=n;)
        {
            if(num==0) break ;
            for(;i<n && check(i+1,n,ans)>=num;i++)
            {
                if(i==1) printf("%lld",a[i]) ;
                else printf(" %lld",a[i]) ;
            }
            if(i==1) printf("%lld",a[i]) ;
            else printf(" %lld",a[i]) ;
            i++ ;
            if(i!=n+1) printf(" /") ;
            num-- ;
        }
        printf("\n") ;
    }
}
