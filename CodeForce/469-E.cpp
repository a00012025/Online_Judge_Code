#include<stdio.h>
main()
{
    long long a;
    scanf("%I64d",&a);
    long long x=45*18 ;
    for(int i=1;i<=17;i++) {x=x*10 ; x=x%a ;}
    long long ans1=a-x,ans2=(long long)1000000000000000000+a-x-1 ;
    printf("%I64d %I64d\n",ans1,ans2) ;
}
