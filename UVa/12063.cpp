#include<bits/stdc++.h>
#define ULL unsigned long long
using namespace std;
ULL dp[67][67][101] ;
main()
{
    int T,tc=0 ; scanf("%d",&T) ;
    while(T--)
    {
        int n,k ; scanf("%d%d",&n,&k) ;
        if(k==0) {printf("Case %d: 0\n",++tc) ; continue ;}
        if(n%2) {printf("Case %d: 0\n",++tc) ; continue ;}
        memset(dp,0,sizeof(dp)) ;
        dp[0][1][1%k]=(ULL)1 ;
        for(int x=0;x<=n;x++) for(int y=1;x+y<=n;y++)
        for(int z=0;z<k;z++)
            dp[x][y+1][(2*z+1)%k]+=dp[x][y][z] ,
            dp[x+1][y][(2*z)%k] += dp[x][y][z] ;
        printf("Case %d: %llu\n",++tc,dp[n/2][n/2][0]) ;
    }
}
