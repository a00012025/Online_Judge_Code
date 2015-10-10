#include<stdio.h>
#include<math.h>
#define DB double
main()
{
    int n,m,tc=0 ;
    while(scanf("%d",&n)==1 && n!=-1)
    {
        scanf("%d",&m) ;
        double ans=0 ;
        for(int i=1;i<m;i++)
        {
            double k=0 ;
            for(int j=i+1;j<=m;j++) k+=log((DB)j) ;
            for(int j=1;j<=m-i;j++) k-=log((DB)j) ;
            k+=n*log((DB)(m-i)) ;
            k-=n*log((DB)m) ;
            if(i%2) ans+=exp(k) ;
            else ans-=exp(k);
        }
        printf("Case %d: %.7lf\n",++tc,ans) ;
    }
}
