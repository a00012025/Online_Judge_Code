#include<stdio.h>
int a[50] ;
main()
{
    int T;
    a[1]=1 ; a[2]=2 ;
    for(int i=3;i<=39;i++) a[i]=a[i-1]+a[i-2] ;
    scanf("%d",&T) ;
    while(T--)
    {
        int n,i;
        scanf("%d",&n) ;
        printf("%d = ",n) ;
        for(i=39;i>=1 && a[i]>n;i--) ;
        for(int j=i;j>=1;j--)
        {
            if(a[j]<=n)
            {
                printf("1") ;
                n-=a[j] ;
            }
            else printf("0") ;
        }
        printf(" (fib)\n") ;
    }
}
