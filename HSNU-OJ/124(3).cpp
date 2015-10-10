#include<bits/stdc++.h>
using namespace std;
const int maxn=10000+10 ;
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
    int n,m ; scanf("%d%d",&n,&m) ;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++)
    {
        scanf("%d",&w[i*m+j]) ;
        for(int z=0;z<4;z++)
        {
            int ni=i+dx[z] , nj=j+dy[z] ;
            if(ni<0 || ni>=n || nj<0 || nj>=m) continue ;
            v[i*m+j].push_back(ni*m+nj) ;
        }
    }

    for(int i=0;i<m*n;i++) d[i]=10001 ;
    for(int i=0;i<n;i++)
        d[i*m]=w[i*m] , pq.push((Q){i*m,w[i*m]}) ,
        d[i*m+m-1]=w[i*m+m-1] , pq.push((Q){i*m+m-1,w[i*m+m-1]}) ;
    for(int i=1;i<m-1;i++)
        d[i]=w[i] , pq.push((Q){i,w[i]}) ,
        d[(n-1)*m+i]=w[(n-1)*m+i] , pq.push((Q){(n-1)*m+i,w[(n-1)*m+i]}) ;
    while(!pq.empty())
    {
        Q u=pq.top() ; pq.pop() ;
        if(done[u.id]) continue ;
        done[u.id]=1 ;
        for(auto x : v[u.id]) if(d[x] > max(d[u.id],w[x]))
            d[x]=max(d[u.id],w[x]) , pq.push((Q){x,d[x]}) ;
    }
    int ans=0 ;
    for(int i=0;i<m*n;i++) ans+=d[i]-w[i] ;
    printf("%d\n",ans) ;
}
