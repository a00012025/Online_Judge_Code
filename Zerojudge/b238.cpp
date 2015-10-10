#include<stdio.h>
#define LL long long
LL a,b,c,d,x[35],y[35],z[35],w[35],MOD ;

void pre_cal()
{
    x[0]=a%MOD ; y[0]=b%MOD ; z[0]=c%MOD ; w[0]=d%MOD ;
    for(int i=0;i<31;i++)
    {
        x[i+1]=(((x[i]*x[i])%MOD + (y[i]*z[i])%MOD) + 2*MOD) % MOD ;
        y[i+1]=(((x[i]*y[i])%MOD + (y[i]*w[i])%MOD) + 2*MOD) % MOD ;
        z[i+1]=(((z[i]*x[i])%MOD + (w[i]*z[i])%MOD) + 2*MOD) % MOD ;
        w[i+1]=(((z[i]*y[i])%MOD + (w[i]*w[i])%MOD) + 2*MOD) % MOD ;
    }
    //printf("%lld,%lld,%lld,%lld\n",x[2],y[2],z[2],w[2]) ;
}

main()
{
    int T ;
    scanf("%d",&T) ;
    while(T--)
    {
        LL t ;
        scanf("%lld%lld%lld%lld%lld%lld",&a,&b,&c,&d,&t,&MOD) ;
        pre_cal() ;
        LL now1=1LL , now2=1LL ;
        while(t)
        {
            int i ; for(i=30;!(t & (1LL<<i));i--) ;
            t -= (1LL<<i) ;
            LL tmp1=now1 , tmp2=now2 ;
            now1 = (((x[i]*tmp1)%MOD + (y[i]*tmp2)%MOD + MOD) + 2*MOD) % MOD ;
            now2 = (((z[i]*tmp1)%MOD + (w[i]*tmp2)%MOD + MOD) + 2*MOD) % MOD ;
        }
        if(now1>now2) printf("Tsundere\n") ;
        else if(now1<now2) printf("Haraguroi\n") ;
        else printf("Normal\n") ;
    }
}
