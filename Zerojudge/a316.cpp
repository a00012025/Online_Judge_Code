#include<stdio.h>
main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,x=1,m=1,ans[70] ;
        scanf("%d",&n) ;
        while(x<=n) {x*=2 ; m++ ;}
        m-- ;
        for(int i=0;i<m;i++) ans[i]=(n & (1<<i)) ? 1 : 0 ;
        for(int i=0;i<m;i++)
        {
            if(i+1<m && ans[i]<=0) {ans[i]+=2 ; ans[i+1]-- ;}
        }
        int ANS=0 ;
        for(int i=0;i<m;i++) ANS+=ans[i] ;
        printf("%d\n",ANS) ;
    }
}
