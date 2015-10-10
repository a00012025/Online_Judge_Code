#include<stdio.h>
#define LL long long
LL f(int type,int k)
{
    if(type==0) return (((LL)9)*k+1)*((LL)3)*k/2 ;
    if(type==1) return (((LL)9)*k-2)*(((LL)3)*k-1)/2 ;
    if(type==2) return (((LL)9)*k-5)*(((LL)3)*k-2)/2 ;
}

main()
{
    LL n;
    scanf("%I64d",&n) ;
    int ans ;
    for(ans=1;f(n%3,ans)<=n;ans++) ;
    printf("%d\n",ans-1) ;
}
