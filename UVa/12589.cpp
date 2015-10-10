#include<bits/stdc++.h>
#define FOR_SET(x,y) for(set<pii>::iterator x=(y).begin();x!=(y).end();x++)
using namespace std;
struct pii
{
    int x,y; // long long ??????
    bool operator < (const pii &rhs) const
    {
        if(x!=rhs.x) return x<rhs.x ;
        else return y<rhs.y ;
    }
}a[60] ;

bool cmp(pii p,pii q)
{
    return p.x*q.y < p.y*q.x ;
}

set<pii> dp[55][55] ;

void try_to_insert(int i,int j,pii p)
{
    if(dp[i][j].count(p)) return ;
    dp[i][j].insert(p) ;
    set<pii>::iterator it=dp[i][j].find(p) ;
    bool keep ; it++ ;
    if(it==dp[i][j].end()) keep=1 ;
    else keep= it->y >= p.y ? 0 : 1 ;
    if(!keep) {dp[i][j].erase(p) ; return ;}
    it-- ;
    while(it!=dp[i][j].begin())
    {
        set<pii>::iterator it2=it ; it2-- ;
        if(it2->y <= p.y) dp[i][j].erase(*it2) ;
        else break ;
    }
}

main()
{
    int T,tc=0 ; scanf("%d",&T) ;
    while(T--)
    {
        int n,k ; scanf("%d%d",&n,&k) ;
        for(int i=1;i<=n;i++) scanf("%d%d",&a[i].x,&a[i].y) ;
        sort(a+1,a+n+1,cmp) ;
        for(int i=0;i<=n;i++) for(int j=0;j<=k;j++) dp[i][j].clear() ;
        dp[0][0].insert((pii){0,0}) ;
        for(int i=1;i<=n;i++) for(int j=0;j<=k;j++)
        {
            if(!j) {dp[i][j].insert((pii){0,0}) ; continue ;}
            FOR_SET(it,dp[i-1][j]) dp[i][j].insert(*it) ;
            FOR_SET(it,dp[i-1][j-1])
            {
                int h=it->x , area=it->y ;
                area += (2*h+a[i].y)*a[i].x ;
                h += a[i].y ;
                try_to_insert(i,j,(pii){h,area}) ;
            }
        }
        printf("Case %d: %d\n",++tc,(*dp[n][k].begin()).y) ;
    }
}
