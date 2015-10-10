#include<stdio.h>
#include<string.h>
#define LL long long
int phi[4000000]={0} ;
LL sum[4000000] ;
void make_phi()
{
    for(int i=2;i<=4000000;i++) if(!phi[i])
        for(int j=i;j<=4000000;j+=i)
        {
            if(!phi[j]) phi[j]=j ;
            phi[j]=(phi[j]/i)*(i-1) ;
        }
    sum[1]=0 ;
    for(int i=2;i<=4000000;i++) sum[i]=sum[i-1]+phi[i] ;
}

main()
{
    make_phi() ;
    int n;
    while(scanf("%d",&n)==1 && n)
    {
        LL ans=(LL)0 ;
        for(int i=1;i<=(n/2)+1;i++)
        {
            int j=(n/i)+1 ; while(i*j>n) j-- ;
            ans+=((LL)i)*sum[j] ;
        }
        printf("%lld\n",ans) ;
    }
}
