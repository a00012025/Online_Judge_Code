#include<bits/stdc++.h>
#define LL long long
#define INF 2147483647
using namespace std;
const int maxn=250000+10 ;
int w[maxn],dx[]={1,-1,0,0},dy[]={0,0,1,-1} ;
vector<int> v[maxn] ;

struct Q
{
    int id,val ;
    bool operator < (const Q &rhs) const
    {
        return val>rhs.val ;
    }
};
priority_queue<Q> pq ;
int d[maxn] ;
bool done[maxn] ;

main()
{
    int n,m ;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=0;i<n;i++) for(int j=0;j<m;j++)
        {
            scanf("%d",&w[i*m+j]) ;
            v[i*m+j].clear() ;
            for(int z=0;z<4;z++)
            {
                int ni=i+dx[z] , nj=j+dy[z] ;
                if(ni<0 || ni>=n || nj<0 || nj>=m) continue ;
                v[i*m+j].push_back(ni*m+nj) ;
            }
        }

        fill(d,d+m*n,INF) ;
        for(int i=0;i<n;i++)
            d[i*m]=w[i*m] , pq.push((Q){i*m,w[i*m]}) ,
            d[i*m+m-1]=w[i*m+m-1] , pq.push((Q){i*m+m-1,w[i*m+m-1]}) ;
        for(int i=1;i<m-1;i++)
            d[i]=w[i] , pq.push((Q){i,w[i]}) ,
            d[(n-1)*m+i]=w[(n-1)*m+i] , pq.push((Q){(n-1)*m+i,w[(n-1)*m+i]}) ;
        memset(done,0,sizeof(done)) ;
        while(!pq.empty())
        {
            Q u=pq.top() ; pq.pop() ;
            if(done[u.id]) continue ;
            done[u.id]=1 ;
            for(auto x : v[u.id]) if(d[x] > max(d[u.id],w[x]))
                d[x]=max(d[u.id],w[x]) , pq.push((Q){x,d[x]}) ;
        }
        LL ans=0LL ;
        for(int i=0;i<m*n;i++) ans+=(LL)d[i]-w[i] ;
        printf("%lld\n",ans) ;
    }
}

