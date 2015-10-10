#include<stdio.h>
main()
{
    int T,n,x,ans,k ; scanf("%d",&T) ;
    while(T--)
    {
        scanf("%d",&n) ; x=ans=0 ;
        while(n--)
            scanf("%d",&k) , ans+=x?(x+1)+(2*x+k-1)*k/2:2+(k-1)*k/2 , x+=k+1 ;
        printf("%d\n",ans) ;
    }
}
