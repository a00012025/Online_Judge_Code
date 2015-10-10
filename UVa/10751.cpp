#include<stdio.h>
#include<math.h>
main()
{
    int T;
    scanf("%d",&T) ;
    while(T--)
    {
        int n;
        scanf("%d",&n) ;
        double ans=sqrt((n-2)*(n-2)*2) ;
        ans *= (n-2) ; ans += 4*n-4 ;
        if(n==1) printf("0.000\n") ;
        else printf("%.3lf\n",ans) ;
    }
}
