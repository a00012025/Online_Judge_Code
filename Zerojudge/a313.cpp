#include<stdio.h>
main()
{
    int T,a[10000];
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n) ;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        int sum=0,ans=0 ;
        for(int i=1;i<=n;i++)
        {
            if(!sum) ans++ ;
            sum+=a[i] ;
        }
        printf("%d\n",ans) ;
    }
}
