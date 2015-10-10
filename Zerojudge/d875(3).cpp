#include<stdio.h>
#define LL long long
main()
{
    LL n;
    while(scanf("%lld",&n)!=EOF)
    {
        LL k;
        for(k=1;k*(k+1)<n;k++) ;
        if(n>k*k)
        {
            LL x=n-k*k ;
            for(int i=1;i<=x;i++) printf("%d ",i) ;
            for(int i=x;i<=k-1;i++) printf("%d ",i) ;
            for(int i=k;i>=1;i--) printf("%d ",i) ;
        }
        else if(n<k*k)
        {
            LL x=n-k*k+k ;
            for(int i=1;i<=x;i++) printf("%d ",i) ;
            for(int i=x;i<=k-1;i++) printf("%d ",i) ;
            for(int i=k-1;i>=1;i--) printf("%d ",i) ;
        }
        else
        {
            for(int i=1;i<=k;i++) printf("%d ",i);
            for(int i=k-1;i>=1;i--) printf("%d ",i) ;
        }
        printf("\n") ;

    }
}
