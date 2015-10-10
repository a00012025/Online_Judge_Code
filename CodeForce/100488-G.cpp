#include<stdio.h>
long long s,a[100001] ;
main()
{
    int n ;
    scanf("%I64d %I64d",&n,&s) ;
    for(int i=1;i<=n;i++) scanf("%I64d",&a[i]) ;
    long long r=1 ;
    int M=0 ;
    while(r<=s)
    {
        if(M==n) break ;
        M++ ;
        r=(long long)r*a[M] ;
    }
    if(r>s && s>0){r=r/a[M] ; M-- ;} long long ans=0 ;
    for(int i=M;i>=1;i--)
    {
        ans+=s/r ;
        s=s-(s/r)*r ;
        r=r/a[i] ;
    }
    printf("%I64d\n",ans+s) ;
}
