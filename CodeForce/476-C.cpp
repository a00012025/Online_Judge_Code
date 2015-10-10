#include<stdio.h>
#define LL long long
#define MOD 1000000007
#define prod(x,y) (((LL)x)*((LL)y))%MOD
main()
{
    LL a,b ;
    scanf("%I64d %I64d",&a,&b) ;
    LL ans1=b*(b-1)/((LL)2) ; ans1%=MOD ;
    LL ans2=a*(a+1)/((LL)2) ; ans2%=MOD ;
    ans2*=b ; ans2%=MOD ;
    ans2+=a ; ans2%=MOD ;
    LL ans=ans1*ans2 ; ans%=MOD ;
    printf("%I64d\n",ans) ;
}
