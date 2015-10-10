#include<stdio.h>
main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        n=9*n ;
        int m=10 , ans=1 ;
        while(m!=1)
        {
            m*=10 ;
            m%=n ;
            ans++ ;
        }
        printf("%d\n",n==9 ? 1 : ans) ;
    }
}
