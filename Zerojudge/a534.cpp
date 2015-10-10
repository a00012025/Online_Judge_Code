#include<bits/stdc++.h>
using namespace std;
const int maxn=1000000+10 ;

int dp[maxn],n,m ;
char s[maxn] ;

int cal(int x,int now,int l,int r)
{
    if(l<-2 || r>2 || r-l>2) return 0 ;
    if(!x) return 1 ;
    if(r==2) return now==1 ? dp[x] : dp[x-1] ;
    if(l==-2) return now==-1 ? dp[x] : dp[x-1] ;
    if(r-l==1) return ((dp[x]+dp[x-1]+m-1)%m) ;

    if(l==-1 && r==1) return now==0 ? dp[x] : dp[x-1] ;
    return ((dp[x-1]*2+dp[x]+m-2)%m) ;
}

main()
{
    scanf("%d%d%s",&n,&m,s+1) ;
    dp[0]=1 ;
    for(int i=1;i<=n;i++)
        dp[i]= i==1 ? 2 : ((2*dp[i-2])%m) ;

    int ans=0 , now=0 , l=0 , r=0 ;
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='L') { now++ ; r=max(r,now) ; continue ; }
        int val=cal(n-i,now+1,l,max(r,now+1)) ;
        ans=(ans+val)%m ;
        now-- ; l=min(l,now) ;
    }
    printf("%d\n",(ans+1)%m) ;
}
