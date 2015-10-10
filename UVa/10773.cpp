#include<stdio.h>
#include<math.h>
main()
{
    int T,tc=0;
    scanf("%d",&T);
    while(T--)
    {
        int d,v,u ;
        scanf("%d%d%d",&d,&v,&u) ;
        if(v==0 || u==0 || u<=v) printf("Case %d: can't determine\n",++tc) ;
        else printf("Case %d: %.3lf\n",++tc,d/sqrt(u*u-v*v)-d/((double)u)) ;
    }
}
