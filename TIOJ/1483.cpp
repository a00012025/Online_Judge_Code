#include<bits/stdc++.h>
#define lowbit(x) (x&-x)
#define MOD 1000000007
using namespace std;
const int maxn=1000+10 ;

int bit[maxn][maxn] ;
void modify(int x,int y,int val)
{
    for(int i=x;i<maxn;i+=lowbit(i))
        for(int j=y;j<maxn;j+=lowbit(j))
        bit[i][j]=(bit[i][j]+val)%MOD ;
}

int query(int x,int y)
{
    int ret=0 ;
    for(int i=x;i;i-=lowbit(i))
        for(int j=y;j;j-=lowbit(j))
        ret=(ret+bit[i][j])%MOD ;
    return ret ;
}

struct P{int x,y;};
vector<P> v[maxn] ;
int ans[maxn][maxn] ;
main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        memset(bit,0,sizeof(bit)) ;
        for(int i=0;i<maxn;i++) v[i].clear() ;
        int n,m ; scanf("%d%d",&n,&m) ;
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
        {
            int x ; scanf("%d",&x) ;
            if(x<0) abort() ;
            v[x].push_back((P){i,j}) ;
        }
        for(int i=0;i<maxn;i++) if(!v[i].empty())
        {
            for(auto j : v[i]) ans[j.x][j.y]=1+query(j.x,j.y) ;
            for(auto j : v[i]) modify(j.x,j.y,ans[j.x][j.y]) ;
        }
        int Ans=0 ;
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
            Ans=(Ans+ans[i][j])%MOD ;
        printf("%d\n",Ans) ;
    }
}
