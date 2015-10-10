#include<stdio.h>
main()
{
    int n,k,ans=0 ; scanf("%d%d",&n,&k) ;
    while(n--)
    {
        int x ; scanf("%d",&x) ;
        if(x%k==0) ans++ ;
    }
    printf("%d\n",ans) ;
}
