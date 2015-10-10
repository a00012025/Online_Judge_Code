#include<stdio.h>
#include<algorithm>
using namespace std;
int n,dp[1000001],item[8] ;

int power(int a,int b)
{
    int ret=1 ;
    for(int i=1;i<=b;i++) ret*=a ;
    return ret ;
}

int digit(int N,int k)
{
    int x=N/(power(10,k)) ; x*=10 ;
    int y=N/(power(10,k-1)) ;
    return y-x ;
}

void init()
{
    for(int i=0;i<power(10,n);i++)
    {
        dp[i]=0 ;
        for(int j=1;j<=n;j++) dp[i]+=digit(i,j)*item[n+1-j] ;
    }
}

main()
{
    int m ;
    while(scanf("%d",&n)!=EOF){
    for(int i=1;i<=n;i++) scanf("%d",&item[i]);
    init() ;
    scanf("%d",&m) ;
    while(m--)
    {
        int a[8],cost ;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
        scanf("%d",&cost) ;
        int id=0 ;
        for(int i=1;i<=n;i++) {id*=10 ; id+=a[i] ;}
        for(int i=1;i<power(10,n);i++)
        {
            int no=0 ;
            for(int j=1;j<=n;j++)
                if(digit(i,j)<a[n+1-j]) {no=1 ; break ;}
            if(no) continue ;
            dp[i]=min(dp[i],dp[i-id]+cost) ;
        }
    }
    int Q ;
    scanf("%d",&Q) ;
    while(Q--)
    {
        int ask[10],id=0 ;
        for(int i=1;i<=n;i++) scanf("%d",&ask[i]) ;
        for(int i=1;i<=n;i++) {id*=10 ; id+=ask[i] ;}
        printf("%d\n",dp[id]) ;
    }
 }
}
