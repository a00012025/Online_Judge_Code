#include<stdio.h>
#include<math.h>
#define LL long long
main()
{
    int n;
    while(scanf("%d",&n)==1 && n)
    {
        LL a=(LL)sqrt(n-0.5) ; a++ ;
        LL k=a*a-a+1 ;
        if(k>=n && a%2==1) printf("%lld %lld\n",a,n-(a-1)*(a-1)) ;
        else if(k<n && a%2==0) printf("%lld %lld\n",a,a*a+1-n) ;
        else if(k>=n && a%2==0) printf("%lld %lld\n",n-(a-1)*(a-1),a) ;
        else if(k<n && a%2==1) printf("%lld %lld\n",a*a+1-n,a) ;
    }
}
