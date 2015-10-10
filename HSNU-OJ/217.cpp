#include<bits/stdc++.h>
#define INF 2000000000
using namespace std;
const int maxn=5000+10 ;

struct P{int id,val;};
int val[maxn],dp[510][maxn],last[510][maxn] ;
char s[maxn] ;
void print(int num,int x)
{
    if(!num) return ;
    print(num-1,last[num][x]) ;
    for(int i=last[num][x]+1;i<=x;i++) printf("%c",s[i]) ;
    printf("\n") ;
}

deque<P> dq ;
int tc=0 ;
void solve()
{
    int n,k,A,B ; scanf("%d%d%d%d%s",&n,&k,&A,&B,s+1) ;
    for(int i=1;i<=n;i++) scanf("%d",&val[i]) ;
    fill(dp[0],dp[0]+n+1,-INF) ; dp[0][0]=0 ;
    for(int i=1;i<=k;i++)
    {
        fill(dp[i],dp[i]+n+1,-INF) ;
        dq.clear() ;
        for(int j=A;j<=n;j++)
        {
            while(!dq.empty() && dq.back().id<j-B)
                dq.pop_back() ;
            while(!dq.empty() && dq.front().val<=dp[i-1][j-A])
                dq.pop_front() ;
            dq.push_front((P){j-A,dp[i-1][j-A]}) ;
            dp[i][j]=dq.back().val+i*val[j] ;
            last[i][j]=dq.back().id ;
        }
    }
    printf("Case #%d:\n",++tc) ;
    if(dp[k][n]<0) printf("Sorry, you're milk cheese.\n") ;
    else printf("%d\n",dp[k][n]) , print(k,n) ;
}

main()
{
    int T ; scanf("%d",&T) ;
    while(T--) solve() ;
}
