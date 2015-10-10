#include<bits/stdc++.h>
#define DB double
using namespace std;
const int maxn=12+2,maxm=400+10 ;

DB p[maxm][maxm],psum[maxm][maxm] ;
int n,m,a[maxn] ;
void cal_p()
{
    p[1][0]=p[1][1]=0.5 ;
    psum[1][0]=0.5 ; psum[1][1]=1.0 ;
    for(int i=2;i<=400;i++) for(int j=0;j<=i;j++)
    {
        if(j==0) p[i][j]=p[i-1][j]*0.5 ;
        else p[i][j]=(p[i-1][j-1]+p[i-1][j])*0.5 ;
        //p[i][j] = 1. / (i + 1);
        psum[i][j]=(j==0?p[i][j]:(psum[i][j-1]+p[i][j])) ;
    }
}

DB getp(int x)
{
    if(x<0 || x>2*m) return 0 ;
    return p[2*m][x] ;
}

DB getpsum(int x,int y)
{
    x=max(x,0) ; y=min(y,2*m) ;
    if(y<x) return 0 ;
    return psum[2*m][y]-(x?psum[2*m][x-1]:0) ;
}

vector<int> bit[1<<maxn] ;
void cal_bit()
{
    for(int i=1;i<(1<<n);i++)
    {
        bit[i].clear() ;
        for(int j=0;j<n;j++) if(i&(1<<j))
            bit[i].push_back(j) ;
    }
}

int now[maxn],score ;
DB ans[maxn] ;
void dfs(int S,int x,int cnt,DB nowp)
{
    if(x==bit[S].size())
    {
        int num=n-__builtin_popcount(S) ;
        if(num+cnt<4) return ;
        for(int i=1;i<=cnt;i++) ans[now[i]]+=nowp ;
        for(auto i : bit[((1<<n)-1)^S])
            ans[i]+=nowp*((DB)4-cnt)/num ;
        return ;
    }
    if(nowp==0.0) return ;
    DB p1=getpsum(0,score-a[bit[S][x]]-1) ;
    DB p2=getpsum(score-a[bit[S][x]]+1,2*m) ;
    dfs(S,x+1,cnt,nowp*p1) ;
    if(cnt<3) now[cnt+1]=bit[S][x] , dfs(S,x+1,cnt+1,nowp*p2) ;
}

void calans()
{
    for(int i=1;i<(1<<n);i++) for(int j=4*m;j>=0;j--)
    {
        DB p0=1.0 ;
        for(auto k : bit[i]) p0*=getp(j-a[k]) ;
        if(p0==0.0) continue ;
        score=j ;
        dfs(((1<<n)-1)^i,0,0,p0) ;
    }
}

main()
{
    cal_p() ;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        cal_bit() ;
        for(int i=0;i<n;i++)
        {
            int x,y ; scanf("%d%d",&x,&y) ;
            a[i]=x+y ;
        }
        memset(ans,0,sizeof(ans)) ;
        calans() ;
        for(int i=0;i<n;i++) printf("%.10f\n",ans[i]) ;
    }
}
