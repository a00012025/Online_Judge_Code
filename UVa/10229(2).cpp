#include<stdio.h>
#define LL long long
#define MOD 524288
LL x[40],y[40],z[40],u[40] ;
main()
{
    x[0]=1LL ; y[0]=1LL ; z[0]=1LL ; u[0]=0LL ;
    for(int i=1;i<=32;i++)
    {
        x[i]=x[i-1]*x[i-1]+y[i-1]*z[i-1] ; x[i]%=MOD ;
        y[i]=x[i-1]*y[i-1]+y[i-1]*u[i-1] ; y[i]%=MOD ;
        z[i]=z[i-1]*x[i-1]+u[i-1]*z[i-1] ; z[i]%=MOD ;
        u[i]=y[i-1]*z[i-1]+u[i-1]*u[i-1] ; u[i]%=MOD ;
    }
        //for(int i=0;i<=5;i++)printf("%I64d %I64d %I64d %I64d\n",x[i],y[i],z[i],u[i]);
    int n,m ;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        LL a=1 , b=0 , now=0LL ;
        if(n==0) a=0LL ;
        int k=30 ;
        m = (1<<m) ;
        while(k>=0)
        {
            while(k>=0 && (now+((1LL)<<k))>n-1) k-- ;
            if(k<0) break ;
            now+=((1LL)<<k) ;
            LL ta=a , tb=b ;
            a=ta*x[k]+tb*y[k] ; a%=m ;
            b=ta*z[k]+tb*u[k] ; b%=m ;
        }
        printf("%lld\n",a%m) ;
    }

}
