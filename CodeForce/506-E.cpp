#include<bits/stdc++.h>
#define MOD 10007
using namespace std;
const int maxn=200+2 ;

int pow(int x,int n)
{
    if(n<=1) return n ? x : 1 ;
    int tmp=pow(x,n/2) ;
    if(n%2) return (tmp*tmp%MOD)*x%MOD ;
    else return tmp*tmp%MOD ;
}

struct mat
{
    int n,m,a[maxn*3/2][maxn*3/2] ;
    mat(int _n,int _m){n=_n , m=_m ; memset(a,0,sizeof(a)) ;}
};

mat mul(const mat &p,const mat &q)
{
    mat r(p.n,q.m) ;
    for(int i=0;i<p.n;i++) for(int j=0;j<q.m;j++)
        for(int k=0;k<p.m;k++)
        r.a[i][j]+=p.a[i][k]*q.a[k][j] ,
        r.a[i][j]%=MOD ;
    return r ;
}

int getnum(mat &p,int st,int ed,int K)
{
    mat q(p.n,1) ; q.a[st][0]=1 ;
    for(;K;K>>=1,p=mul(p,p)) if(K&1) q=mul(p,q) ;
    return q.a[ed][0] ;
}

int t[maxn][maxn] ;
int solve(int *d,int n,int K,int type)
{/// coordinate : ( x , ceil((n-x)/2) ) => (red number , green number)
    memset(t,0,sizeof(t)) ;
    int ha=(n+1)/2 ;
    for(int i=0;i<=n;i++) t[i][(n-i+1)/2]=d[i] ;
    for(int i=0;i<n;i++) for(int j=1;j<=ha;j++)
        t[i+1][j]=(t[i+1][j]+t[i][j])%MOD ,
        t[i+1][j-1]=(t[i+1][j-1]+t[i][j])%MOD ,
        t[i][j]=0 ;

    int GOAL=0 ;
    mat p(n+ha+1,n+ha+1) ;
    for(int i=2;i<=n+ha;i++) p.a[i][i-1]=1 ;
    for(int i=1;i<=n+ha;i++) p.a[i][i]=(i<=n ? 24 : 25) ;
    for(int i=ha;i<=n+ha;i++) p.a[GOAL][i]=(i<=n ? t[i][0] : t[n][i-n]) ;
    p.a[GOAL][GOAL]=(type==1 ? 26 : 25) ;
    return getnum(p,1,0,K) ;
}

char s[maxn] ;
int dp[maxn][maxn][maxn] ;
void DP(int n,int type)
{
    memset(dp,0,sizeof(dp)) ;
    for(int i=n;i>=1;i--) for(int j=i;j<=n;j++)
    {
        if(type==1)
        {
            if(i==j){dp[i][j][0]=1 ; continue ;}
        }
        else
        {
            if(i==j) continue ;
            if(j==i+1){dp[i][j][0]=(s[i]==s[j]?1:0) ; continue ;}
        }
        if(s[i]==s[j])
        {
            for(int k=0;k<=n;k++)
                dp[i][j][k]=dp[i+1][j-1][k] ;
            if(j==i+1) dp[i][j][0]=1 ;
        }
        else
        {
            dp[i][j][0]=0 ;
            for(int k=1;k<=n;k++)
                dp[i][j][k]=(dp[i+1][j][k-1]+dp[i][j-1][k-1])%MOD ;
        }
    }
}

main()
{
    int n,m ; scanf("%s%d",s+1,&m) ;
    n=strlen(s+1) ;

    DP(n,1) ;

    int K=(n+m+1)/2 ;
    int ans=solve(dp[1][n],n,K,1) ;
    if(n==1 || (n+m)%2==0){printf("%d\n",ans) ; return 0 ;}
    if(n==2 && s[1]==s[2])
        ans=(ans-pow(25,K-1)+MOD)%MOD ;
    else if(n!=2)
    {
        DP(n,2) ;
        ans=(ans-solve(dp[1][n],n-2,K-1,2)+MOD)%MOD ;
    }
    printf("%d\n",ans) ;
}
