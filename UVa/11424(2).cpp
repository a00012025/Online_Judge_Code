#include<stdio.h>
#include<string.h>
#define LL long long
int phi[201000]={0} ;
LL ans[200000] ;
void make_phi()
{
    for(int i=2;i<=201000;i++) if(!phi[i])
        for(int j=i;j<=201000;j+=i)
        {
            if(!phi[j]) phi[j]=j ;
            phi[j]=(phi[j]/i)*(i-1) ;
        }
}

main()
{
    make_phi() ;
    for(int i=0;i<=200000;i++) ans[i]=(LL)0 ;
    for(int i=1;i<=200000;i++)
        for(int j=2*i;j<=200000;j+=i) ans[j]+=i*phi[j/i] ;
    for(int i=1;i<=200000;i++) ans[i]+=ans[i-1] ;
    int n;
    while(scanf("%d",&n)==1 && n) printf("%lld\n",ans[n]) ;
}
