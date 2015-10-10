#include<stdio.h>
#include<string.h>
#define LL long long
LL ans[1001000] ;
main()
{
    int n,tc=0 ;
    memset(ans,-1,sizeof(ans)) ;
    while(scanf("%d",&n)==1 && n)
    {
        printf("Case %d: ",++tc) ;
        if(ans[n]>=0) printf("%d\n",ans[n]) ;
        else
        {
            ans[n]=0 ;
            for(int a=1;;a++)
            {
                if(n-3*a-3<0) break ;
                ans[n]+=((n-3*a-3)/2)+1 ;
            }
            printf("%lld\n",ans[n]) ;
        }
    }
}
