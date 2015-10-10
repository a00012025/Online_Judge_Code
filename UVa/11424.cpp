#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define LL long long
int phi[200001],p[100000],cnt ;
bool a[200001] ;
LL ans[200001] ;

void make_prime()
{
    for(int i=1;i<=200000;i++) a[i]=1 ;
    for(int i=2;i<=500;i++) if(a[i])
        for(int j=i*i;j<=200000;j+=i) a[j]=0 ;
    for(int i=2;i<=200000;i++) if(a[i]) p[++cnt]=i ;
}

void make_phi()
{
    for(int i=1;i<=200000;i++) phi[i]=1 ;
    for(int i=1;i<=cnt;i++)
    {
        LL q=p[i] ;
        while(q<=200000)
        {
            for(int j=1;j*q<=200000;j++) if(j%p[i])
                phi[j*q]*=(q-(q/p[i])) ;
            q*=p[i] ;
        }
    }
}

main()
{
    make_prime() ;
    make_phi() ;
    for(int i=0;i<=200000;i++) ans[i]=(LL)0 ;
    for(int i=1;i<=200000;i++)
    {
        for(int j=2;i*j<=200000;j++) ans[i*j]+=i*phi[j] ;
    }
    for(int i=1;i<=200000;i++) ans[i]+=ans[i-1] ;
    int n;
    while(scanf("%d",&n)==1 && n)
    {
        printf("%lld\n",ans[n]);
    }

}
