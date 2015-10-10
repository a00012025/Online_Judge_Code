#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10 ;

struct P{int to,dis;};
vector<P> v[maxn] ;

int n,anc[18][maxn],dis[maxn] ;
void dfs(int x,int f,int d)
{
    anc[0][x]=f ; dis[x]=d ;
    for(auto i : v[x]) if(i.to!=f)
        dfs(i.to,x,d+i.dis) ;
}

int get_cent()
{
    dfs(1,1,0) ;
    int id,M=-1 ;
    for(int i=1;i<=n;i++) if(dis[i]>M) M=dis[id=i] ;
    dfs(id,id,0) ;
    int id2 ; M=-1 ;
    for(int i=1;i<=n;i++) if(dis[i]>M) M=dis[id2=i] ;

    int mi=M , cent ;
    for(int i=id2;i!=id;i=anc[0][i])
    {
        int val=max(dis[i],M-dis[i]) ;
        if(val<=mi) mi=val , cent=i ;
    }
    return cent ;
}

int mson[maxn],mdis[maxn] ;
void dfs2(int x,int f,int d)
{
    anc[0][x]=f ;
    for(int i=1;i<18;i++) anc[i][x]=anc[i-1][anc[i-1][x]] ;
    dis[x]=d ; mson[x]=-1 ; mdis[x]=0 ;
    for(auto i : v[x]) if(i.to!=f)
    {
        dfs2(i.to,x,d+i.dis) ;
        if(i.dis+mdis[i.to]>mdis[x])
            mdis[x]=i.dis+mdis[mson[x]=i.to] ;
    }
}

struct Q
{
    int id,val ;
    bool operator < (const Q &rhs) const
    {
        return val<rhs.val ;
    }
};

int chid[maxn],chcnt=0 ;
int len[maxn] ;
priority_queue<Q> pq ;
void build(int root)
{
    pq.push((Q){root,mdis[root]}) ;
    while(!pq.empty())
    {
        Q u=pq.top() ; pq.pop() ;
        len[++chcnt]=u.val ;
        for(int i=u.id;i!=-1;i=mson[i])
        {
            chid[i]=chcnt ;
            for(auto j : v[i]) if(j.to!=anc[0][i] && j.to!=mson[i])
                pq.push((Q){j.to,j.dis+mdis[j.to]}) ;
        }
    }
}

int lsum[maxn] ;
main()
{
    int Q ; scanf("%d%d",&n,&Q) ;
    for(int i=1;i<n;i++)
    {
        int x,y,dis ; scanf("%d%d%d",&x,&y,&dis) ;
        v[x].push_back((P){y,dis}) ;
        v[y].push_back((P){x,dis}) ;
    }

    int root=get_cent() ;
    dfs2(root,root,0) ;
    build(root) ;
    for(int i=1;i<=chcnt;i++) lsum[i]=lsum[i-1]+len[i] ;
    for(int q=1,last=0;q<=Q;q++)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        if(q>1) x=(x+last-1)%n+1 , y=(y+last-1)%n+1 ;
        if(2*y>=chcnt) printf("%d\n",last=lsum[chcnt]) ;
        else if(chid[x]<=2*y) printf("%d\n",last=lsum[2*y]) ;
        else
        {
            int x2=x ;
            for(int i=17;i>=0;i--) if(chid[anc[i][x2]]>2*y)
                x2=anc[i][x2] ;
            x2=anc[0][x2] ;
            int ans=lsum[2*y]+mdis[x]+(dis[x]-dis[x2]) ;
            printf("%d\n",last=ans-min(len[2*y],mdis[x2])) ;
        }
    }
}
