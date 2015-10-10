#include<bits/stdc++.h>
using namespace std;
struct P
{
    int id,val ;
    bool operator < (const P &rhs) const
    {
        return val==rhs.val ? id<rhs.id : val<rhs.val ;
    }
};

int w[101],fa[101],fdis[101] ;
int d[101],num[101],tot[101] ;
bool done[101] ;
vector<int> v[101] ;
priority_queue<P> pq ;
void dfs0(int x)
{
    num[x]=w[x] ; tot[x]=w[x]*d[x] ;
    for(int i=0;i<v[x].size();i++) if(!done[v[x][i]])
    {
        d[v[x][i]]=d[x]+fdis[v[x][i]] ;
        dfs0(v[x][i]) ;
        num[x]+=num[v[x][i]] ;
        tot[x]+=tot[v[x][i]] ;
    }
    if(d[x]) pq.push((P){x,d[x]*num[x]}) ;
}

main()
{
    int n,k ; scanf("%d%d",&n,&k) ;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d",&w[i],&fa[i],&fdis[i]) ;
        v[fa[i]].push_back(i) ;
    }
    done[0]=1 ;
    dfs0(0) ;
    int ans=tot[0] , cnt=0 ;
    while(cnt<k)
    {
        P u=pq.top() ; pq.pop() ;
        if(done[u.id] || d[u.id]*num[u.id]!=u.val) continue ;
        ans-=d[u.id]*num[u.id] ; cnt++ ;
        d[u.id]=0 ; done[u.id]=1 ;
        dfs0(u.id) ;
        for(int i=0;i<=n;i++) if(done[i]) dfs0(i) ;
    }
    printf("%d\n",ans) ;
}
