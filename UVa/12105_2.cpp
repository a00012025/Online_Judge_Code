#include<stdio.h>
#include<algorithm>
#define INF 100000000
using namespace std;
int pw[10][101],dp[101][3001],n,m ;
int num[10]={6,2,5,5,4,5,6,3,7,6} ;

void find_pow()
{
    for(int i=0;i<=9;i++)
    {
        int M=i%m ;
        for(int j=0;j<61;j++)
        {
            pw[i][j]=M ;
            M*=10 ; M%=m ;
        }
    }
}

main()
{
        //freopen("1.txt","r",stdin) ;
        //freopen("2.txt","w",stdout) ;

    int tc=0 ;
    while(scanf("%d",&n)==1 && n)
    {
        scanf("%d",&m) ;
        find_pow() ;
        for(int i=0;i<=n/2+1;i++) for(int j=0;j<m;j++) dp[i][j]=INF ;
        dp[0][0]=0 ;
        //for(int i=0;i<10;i++) dp[1][i%m]=min(dp[1][i%m],num[i]) ;
        for(int i=1;i<=n/2+1;i++) for(int j=0;j<m;j++) for(int k=1;k<=9;k++)
        {
            int nj=(j-pw[k][i-1]+2*m)%m ;
            for(int z=1;z<=i;z++)
                dp[i][j]=min(dp[i][j],dp[i-z][nj]+num[k]+(z-1)*num[0]) ;
        }
        int ans ;
        for(ans=(n/2)+1;ans>=1 && dp[ans][0]>n;ans--) ;
        printf("Case %d: ",++tc) ;
        if(ans==0)
        {
            printf("%d\n",n>=6 ? 0 : -1) ;
            continue ;
        }
        int nowr=0,nownum=n ;
        for(;ans>=1;)
        {
            bool ok=0 ;
            for(int z=1;!ok && z<=ans;z++) for(int k=9;!ok && k>=1;k--)
            {
                int newr=(nowr-pw[k][ans-1]+2*m)%m ;
                if(num[k]+(z-1)*num[0]+dp[ans-z][newr]<=nownum)
                {
                    printf("%d",k) ;
                    for(int zz=1;zz<z;zz++) printf("0") ;
                    nowr=newr ;
                    nownum -= num[k]+(z-1)*num[0] ;
                    ans-=z ;
                    ok=1 ; break ;
                }
            }
        }
        printf("\n") ;
    }
}
