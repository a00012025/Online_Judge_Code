#include<bits/stdc++.h>
#define MOD 32768
using namespace std;
const int maxn=2000+10 ;
struct P{int to,dis;};

int num[maxn][200+10] ;
int d[maxn][200+10],m,n ;
bool vis[maxn] ;
vector<P> v[maxn] ;
char name[200+10][200] ;

void dp(int x)
{
    if(vis[x]) return ;
    vis[x]=1 ;
    for(auto j : v[x])
    {
        dp(j.to) ;
        for(int i=1;i<=m;i++)
        {
            num[x][i]=(num[x][i]+num[j.to][i])%MOD ;
            d[x][i]=(d[x][i]+num[j.to][i]*j.dis+d[j.to][i])%MOD ;
        }
    }
    if(x>=1 && x<=m) num[x][x]++ ;
}

main()
{
    int T,tc=0 ; scanf("%d",&T) ;
    while(T--)
    {
        int x ; scanf("%d%d%d",&m,&n,&x) ;
        for(int i=0;i<maxn;i++) v[i].clear() ;
        for(int i=1;i<=m;i++) scanf("%s",name[i]) ;
        while(x--)
        {
            int x,y,dis ; scanf("%d%d%d",&x,&y,&dis) ;
            dis%=MOD ;
            v[x].push_back((P){y,dis}) ;
        }
        memset(vis,0,sizeof(vis)) ;
        memset(d,0,sizeof(d)) ;
        memset(num,0,sizeof(num)) ;
        dp(0) ;

        printf("Game #%d\n",++tc) ;
        for(int i=1;i<=m;i++) printf("%s: %d\n",name[i],d[0][i]) ;
    }
}
