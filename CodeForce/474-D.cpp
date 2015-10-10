#include<stdio.h>
#define MOD 1000000007 ;
int ans[100001],sum[100001] ;
main()
{
    int T,k ;
    scanf("%d %d",&T,&k);
    ans[0]=1 ; sum[0]=1 ;
    for(int i=1;i<=100000;i++)
    {
        if(i>=k) ans[i]=ans[i-1]+ans[i-k] ;
        else ans[i]=ans[i-1] ;
        ans[i]%=MOD ;
        sum[i]=sum[i-1]+ans[i] ;
        sum[i]%=MOD;
    }
    while(T--)
    {
        int a,b ;
        scanf("%d%d",&a,&b) ;
        int k=sum[b]-sum[a-1] ;
        while(k<0) k+=MOD ;
        printf("%d\n",k) ;
    }
}
