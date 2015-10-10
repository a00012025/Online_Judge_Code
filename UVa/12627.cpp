#include<stdio.h>
#define LL long long

LL red(int n,int i)
{
    if(i==0) return 0LL ;
    if(n==0) return 1LL ;
    if(i<=(1<<(n-1))) return 2*red(n-1,i) ;
    else
    {
        LL M=1 ;
        for(int j=1;j<=n-1;j++) M*=3 ;
        return red(n-1,i-(1<<(n-1))) + 2*M ;
    }
}

main()
{
    int T,tc=0 ;
    scanf("%d",&T) ;
    while(T--)
    {
        int k,a,b ;
        scanf("%d%d%d",&k,&a,&b) ;
        printf("Case %d: %lld\n",++tc,red(k,b)-red(k,a-1)) ;
    }
}
