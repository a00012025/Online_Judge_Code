#include<bits/stdc++.h>
#define LL long long
#define INF (1LL<<60)
using namespace std;
struct P{int to,dis;};

LL dp[14][1<<14] ;
int num[14][1<<14] ;
vector<P> v[14] ;

struct Q
{
    int id ; LL dis ;
    bool operator < (const Q &rhs) const
    {
        return dis>rhs.dis ;
    }
};
priority_queue<Q> pq ;
LL d[14] ;
bool done[14] ;

main()
{
    int n,m ; scanf("%d%d",&n,&m) ;
    while(m--)
    {
        int x,y,dis ; scanf("%d%d%d",&x,&y,&dis) ;
        v[x].push_back((P){y,dis}) ;
        v[y].push_back((P){x,dis}) ;
    }
    int S=0 ; scanf("%d",&m) ;
    int sta=-1 ;
    while(m--)
    {
        int x ; scanf("%d",&x) ;
        S|=(1<<x) ;
        if(sta==-1) sta=x ;
    }

    for(int i=0;i<n;i++) for(int j=0;j<(1<<n);j++) dp[i][j]=INF ;
    for(int i=0;i<n;i++) dp[i][0]=0 ;
    for(int i=1;i<(1<<n);i++) if( i==(S&i) )
    {
        while(!pq.empty()) pq.pop() ;
        fill(d,d+n,INF) ; memset(done,0,sizeof(done)) ;
        for(int j=0;j<n;j++) if(i&(1<<j))
        {
            d[j]=dp[j][i^(1<<j)] ;
            pq.push((Q){j,d[j]}) ;
        }
        while(!pq.empty())
        {
            Q u=pq.top() ; pq.pop() ;
            if(done[u.id]) continue ;
            done[u.id]=1 ;
            for(auto x : v[u.id]) if(!(i&(1<<x.to)))
            {
                if(d[x.to] > d[u.id]+x.dis)
                {
                    d[x.to]=d[u.id]+x.dis ;
                    num[x.to][i]=u.id ;
                    pq.push((Q){x.to,d[x.to]}) ;
                }
                else if(d[x.to]==d[u.id]+x.dis && num[x.to][i]>u.id)
                    num[x.to][i]=u.id ;
            }
        }
        for(int j=0;j<n;j++) if(!(i&(1<<j)))
            dp[j][i]=d[j] ;
    }
    printf("Minimum travel distance: %lld\n",dp[sta][S^(1<<sta)]) ;
    printf("Travel route:") ;
    int now=sta ; S^=(1<<sta) ;
    while(1)
    {
        printf(" %d",now) ;
        if(S&(1<<now)) S^=(1<<now) ;
        if(!S) break ;
        now=num[now][S] ;
    }
    printf("\n") ;
}
