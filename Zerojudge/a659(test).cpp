 #include<stdio.h>
#include<string.h>
#define LL long long
#define N 500100
LL a1[5000000],a2[5000000],num[501001] ;
main()
{
    int cnt=0 ;
    for(LL i=2;i<=2*N;i*=2)
        for(LL j=1;j<i/2;j+=2)
            for(LL k=1;j*k<=N && (i-j)*k<=N;k++)
                {cnt++ ; a1[cnt]=j*k ; a2[cnt]=(i-j)*k ;}
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,x;
        scanf("%d",&n) ;
        memset(num,0,sizeof(num)) ;
        for(int i=1;i<=n;i++) {scanf("%d",&x) ; num[x]++ ;}
        LL ans=0 ;
        for(int i=1;i<=cnt;i++)
            ans+=num[a1[i]]*num[a2[i]] ;
        for(int i=1;i<=N;i++)
            ans+=num[i]*(num[i]-1)/2 ;
        printf("%lld\n",ans) ;
    }
}
