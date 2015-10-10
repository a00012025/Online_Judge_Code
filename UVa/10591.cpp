#include<stdio.h>
bool ans[2000] ;
int f(int n)
{
    int ret=0 ;
    while(n) {ret += (n%10)*(n%10) ; n/=10 ;}
    return ret ;
}

void init()
{
    int cnt=0 ;
    for(int i=1;i<=1000;i++)
    {
        cnt=0 ;
        int x=i ;
        while(x!=1) {x=f(x) ; cnt++ ; if(cnt>=1000)break ; }
        if(x==1) ans[i]=1 ;
        else ans[i]=0 ;
    }
}

main()
{
    int T,tc=0;
    scanf("%d",&T);
    init() ;
    while(T--)
    {
        int n,k;
        scanf("%d",&n) ;
        if(ans[f(n)]==1)printf("Case #%d: %d is a Happy number.\n",++tc,n);
        else printf("Case #%d: %d is an Unhappy number.\n",++tc,n);
    }
}
