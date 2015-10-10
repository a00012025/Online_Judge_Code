//#define NDEBUG
#include<bits/stdc++.h>
#ifdef NDEBUG
#define debugf(...) (void(0))
#else
#define debugf(...) printf(__VA_ARGVS__)
#endif // NDEBUG
#define MOD 1000000007
using namespace std;

bool s1[1<<12],s2[1<<12] ;
void find_s1_and_s2(int k) /// s1 : k , s2 : k+1
{
    memset(s1,0,sizeof(s1)) ;
    memset(s2,0,sizeof(s2)) ;
    if(k%2==1)
    {
        for(int i=0;i<(1<<( (k+1)/2 ));i++)
        {
            int x=i ;
            for(int j=(k+1)/2 ; j<k ; j++) if(i & (1<<(k-1-j)))
                x+=(1<<j) ;
            s1[x]=1 ;
        }
        for(int i=0;i<(1<<((k+1)/2));i++)
        {
            int x=i ;
            for(int j=(k/2)+1;j<=k;j++) if(i & (1<<(k-j)))
                x+=(1<<j) ;
            s2[x]=1 ;
        }
    }
    else
    {
        for(int i=0;i<(1<<(k/2));i++)
        {
            int x=i ;
            for(int j=(k/2); j<k  ;j++) if(i & (1<<(k-1-j)))
                x+=(1<<j) ;
            s1[x]=1 ;
        }
        for(int i=0;i<(1<<( (k/2)+1 ));i++)
        {
            int x=i ;
            for(int j=(k/2)+1 ; j<=k ; j++) if(i & (1<<(k-j)))
                x+=(1<<j) ;
            s2[x]=1 ;
        }
    }
}

int dp[410][1<<11] ;
main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int n,k ; scanf("%d%d",&n,&k) ;
        if(n<k) {printf("%d\n",1<<n) ; continue ;}
        find_s1_and_s2(k) ;
        memset(dp,0,sizeof(dp)) ;
        for(int i=0;i<(1<<k);i++) dp[k][i]= s1[i] ? 0 : 1 ;
        for(int i=k;i<n;i++) for(int j=0;j<(1<<k);j++) if(dp[i][j])
        for(int z=0;z<2;z++)
        {
            int nx1=j*2+z , nx2=(nx1 & (1<<k)) ? (nx1 ^ (1<<k)) : (nx1) ;
            if(!s2[nx1] && !s1[nx2])
            {
                dp[i+1][nx2] += dp[i][j] ;
                dp[i+1][nx2] %= MOD ;
            }
        }
        int ans=0 ;
        for(int i=0;i<(1<<k);i++) ans+=dp[n][i] , ans%=MOD ;
        printf("%d\n",ans) ;
         /// % MOD !!!!!!!!!
    }
}
