#include<stdio.h>
double p[30] ;

int bit_cnt(int x)
{
    if(!x) return 0 ;
    return x%2 ? 1+bit_cnt(x/2) : bit_cnt(x/2) ;
}

double ans[30] ;
main()
{
    int n,k,tc=0 ;
    while(scanf("%d%d",&n,&k)==2 && n+k)
    {
        for(int i=0;i<n;i++) scanf("%lf",&p[i]) ;
        double p2=0.0 ;
        for(int i=0;i<n;i++) ans[i]=0.0 ;
        for(int i=0;i<(1<<n);i++) if(bit_cnt(i)==k)
        {
            double d=1.0 ;
            for(int j=0;j<n;j++) d *= ( (i&(1<<j)) ? (p[j]) : (1-p[j]) ) ;
            p2+=d ;
            for(int j=0;j<n;j++) if(i&(1<<j))
                ans[j]+=d ;
        }
        printf("Case %d:\n",++tc) ;
        for(int i=0;i<n;i++) printf("%lf\n",ans[i]/p2) ;
    }
}
