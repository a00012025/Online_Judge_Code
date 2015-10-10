#include<stdio.h>
int gcd(int x,int y)
{
    while(x!=0 && y!=0)
    {
        if(x>y) x=x%y ;
        else y=y%x ;
    }
    if(!x) return y ;
    else return x ;
}
main()
{
    int T;
    scanf("%d",&T) ;
    while(T--)
    {
        int n,a[10001] ;
        scanf("%d",&n) ;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
        int ans=a[1] ;
        for(int i=2;i<=n;i++) ans=gcd(ans,a[i]);
        printf("%d\n",ans) ;
    }
}
