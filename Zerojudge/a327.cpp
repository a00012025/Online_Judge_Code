#include<stdio.h>
#include<algorithm>
using namespace std;
struct P {int x,y;}a[50100];
bool cmp(P a,P b)
{
    if(a.x != b.x) return a.x<b.x ;
    else return a.y>b.y ;
}
int n,m ;
int dp[50100],len[50100] ;
const int INF=1000000000 ;
int solve()
{
    dp[0]=-1 ; int now=0 ;
    for(int i=0;i<m;i++)
    {
        int id=lower_bound(dp,dp+now+1,a[i].y) - dp ;
        id-- ;
        if(id==now)
        {
            dp[now+1]=a[i].y ;
            len[i]=now+1 ;
            now++ ;
        }
        else
        {
            len[i]=id+1 ;
            dp[id+1]=min(dp[id+1],a[i].y) ;
        }
        //for(int j=0;j<=now;j++) printf("%d,",dp[j]) ;
        //printf("\n") ;
    }
    return now ;
}

main()
{
    int T ;
    scanf("%d",&T) ;
    while(T--)
    {
        scanf("%d%d",&n,&m) ;
        a[0]=(P){n,n} ;
        for(int i=0;i<m;i++) scanf("%d",&a[i+1].x) ;
        for(int i=0;i<m;i++) scanf("%d",&a[i+1].y) ;
        m++ ; sort(a,a+m,cmp) ;
        int L=solve() ;
        printf("%d\n",2*(n-1)-L+1) ;
    }
}
