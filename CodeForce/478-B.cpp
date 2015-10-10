#include<stdio.h>
#define LL long long
main()
{
    LL n,m,ans1,ans2 ;
    scanf("%I64d %I64d",&n,&m) ;
    ans2=(n-m+1)*(n-m)/2 ;
    if(m==1) ans1=ans2 ;
    else
    {
        LL q=n/m , r=n%m ;
        ans1=0 ;
        ans1+=((LL)r)*((q+1)*q/2) ;
        ans1+=((LL)m-r)*((q-1)*q/2) ;
    }
    printf("%I64d %I64d\n",ans1,ans2) ;
}
