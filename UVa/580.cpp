#include<stdio.h>
#define LL long long
LL ans[31] ;
main()
{
    ans[1]=ans[2]=0 ; ans[3]=1 ; ans[4]=3 ;
    LL k=4 ;
    for(int i=5;i<=30;i++,k*=2) ans[i]=ans[i-1]+ans[i-2]+ans[i-3]+k ;
    int n;
    while(scanf("%d",&n)==1 && n) printf("%lld\n",ans[n]) ;
}
