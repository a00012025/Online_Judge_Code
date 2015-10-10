#include<bits/stdc++.h>
#define LL long long
#define MOD 1000000007
using namespace std;

LL x[50],y[50],z[50],w[50] ;

void pre_cal()
{
    x[0]=1 ; y[0]=MOD-1 ; z[0]=1 ; w[0]=0 ;
    for(int i=0;i<=32;i++)
    {
        x[i+1]= (x[i]*x[i]%MOD)+(y[i]*z[i]%MOD) ; x[i+1]=((x[i+1]%MOD)+MOD)%MOD ;
        y[i+1]= (x[i]*y[i]%MOD)+(y[i]*w[i]%MOD) ; y[i+1]=((y[i+1]%MOD)+MOD)%MOD ;
        z[i+1]= (z[i]*x[i]%MOD)+(w[i]*z[i]%MOD) ; z[i+1]=((z[i+1]%MOD)+MOD)%MOD ;
        w[i+1]= (z[i]*y[i]%MOD)+(w[i]*w[i]%MOD) ; w[i+1]=((w[i+1]%MOD)+MOD)%MOD ;
    }
}

main()
{
    pre_cal() ;
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        LL a,b ; scanf("%lld%lld",&a,&b) ;
        int n ; scanf("%d",&n) ;
        a=((a%MOD)+MOD)%MOD ;
        b=((b%MOD)+MOD)%MOD ;
        if(n==1) printf("%lld\n",a) ;
        else if(n==2) printf("%lld\n",b) ;
        else
        {
            swap(a,b) ;
            int t=n-2 ;
            while(t)
            {
                int i=32 ;
                while((1LL<<i) > t) i-- ;
                LL a2=x[i]*a+y[i]*b , b2=z[i]*a+w[i]*b ;
                a=a2%MOD ; b=b2%MOD ;
                t-=(1<<i) ;
            }
            printf("%lld\n",a) ;
        }
    }
}
