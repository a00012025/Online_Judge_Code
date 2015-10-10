#include<bits/stdc++.h>
using namespace std;
struct P{int ed,t1,t2 ;};
struct Q
{
    int id,t ;
    bool operator < (const Q &rhs) const
    {
        return t>rhs.t ;
    }
};
struct R{int x,y ;};
bool cmp(P x,P y){ return x.t1<y.t1 ; }
const int INF=2000000000 ;
vector<P> v[200001] ;
int ans[200001],n ;

int find_in_v(int id,int val)
{
    if(v[id].size() && v[id][0].t1>=val) return 0 ;
    int l=0 , r=v[id].size() ;
    while(r-l>1)
    {
        int mid=(r+l)/2 ;
        if(v[id][mid].t1>=val) r=mid ;
        else l=mid ;
    }
    return r ;
}

bool done[100001] ;
int d[100001] ;
int dijkstra(int st,int t0)
{
    priority_queue<Q> pq ; pq.push((Q){st,t0}) ;
    memset(done,0,sizeof(done)) ;
    memset(d,-1,sizeof(d)) ; d[st]=t0 ;

    while(!pq.empty())
    {
        Q u=pq.top() ; pq.pop() ;
        if(u.id==n) return d[n] ;
        if(done[u.id]) continue ;
        done[u.id]=1 ;
        int id2=find_in_v(u.id,d[u.id]) ;
        for(int i=id2;i<v[u.id].size();i++)
        {
            if(d[v[u.id][i].ed]==-1 || d[v[u.id][i].ed] > v[u.id][i].t2)
            {
                d[v[u.id][i].ed] = v[u.id][i].t2 ;
                pq.push((Q){v[u.id][i].ed , v[u.id][i].t2 }) ;
            }
        }
    }
    return INF ;
}

R ANS[500001] ;

int find_in_ans(int num,int val)
{
    int l=0 , r=num ;
    while(r-l>1)
    {
        int mid=(r+l)/2 ;
        if(ANS[mid].y<=val) l=mid ;
        else r=mid ;
    }
    return l ;
}

main()
{
    int m ; scanf("%d%d",&n,&m) ;
    while(m--)
    {
        int st,t1,ed,t2 ; scanf("%d%d%d%d",&st,&ed,&t1,&t2) ;
        v[st].push_back((P){ed,t1,t2}) ;
    }
    for(int i=1;i<=n;i++) sort(v[i].begin(),v[i].end(),cmp) ;
    for(int i=0;i<v[1].size();i++)
    {
        int dn=dijkstra(v[1][i].ed,v[1][i].t2) ;
        ans[i]= dn==INF ? -1 : dn ;
        //printf("ans[%d]=%d\n",i,ans[i]) ;
    }
    int num=0 ;
    for(int i=0;i<v[1].size();i++) if(ans[i]!=-1)
    {
        //if(!num) { ANS[num++]=(R){v[1][i].t1,ans[i]} ; continue ; }
        if(num && ANS[num-1].x==v[1][i].t1 && ANS[num-1].y < ans[i]) continue ;
        while(num && ans[i] <= ANS[num-1].y) num-- ;
        ANS[num++]=(R){v[1][i].t1,ans[i]} ;
    }
    int Q ; scanf("%d",&Q) ;
    while(Q--)
    {
        int x ; scanf("%d",&x) ;
        if(num==0 || ANS[0].y > x) { printf("-1\n") ; continue ; }
        int id=find_in_ans(num,x) ;
        printf("%d\n",ANS[id].x) ;
    }
}
