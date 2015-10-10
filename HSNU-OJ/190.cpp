#define NDEBUG
#ifdef NDEBUG
#define debugf(...) ((void)0)
#else
#define debugf(...) printf(__VA_ARGS__)
#endif // NDEBUG
#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=100000+100 ;
struct P{int ed,dis;};
struct Q
{
    int id ; LL dis;
    bool operator < (const Q &rhs) const
    {
        if(dis!=rhs.dis) return dis<rhs.dis ;
        else return id<rhs.id ;
    }
};

vector<P> v[maxn] ;
int n,k ;

LL dijkstra(int s)
{
    set<Q> pq ;
    set<LL> st ;
    pq.insert((Q){s,0LL}) ; st.insert(0LL) ;
    int num=k ; LL last=(LL)(-1) ;
    while(!pq.empty())
    {
        set<Q>::iterator it=pq.begin() ;/*
            debugf("pq : ") ;
            for(set<Q>::iterator it3=pq.begin();it3!=pq.end();it3++) debugf("(%d,%d),",it3->id,it3->dis) ;
            debugf("\n set : ") ;
            for(set<LL>::iterator it3=st.begin();it3!=st.end();it3++) debugf("%I64d,",*it3) ;
            debugf("\n") ;*/
        Q u=*it ; debugf("(%d,%I64d)\n",u.id,u.dis) ;
        if(u.dis!=last) { num-- ; if(last!=(LL)(-1)) st.erase(last) ; last=u.dis ;  }
        if(num==0) return u.dis ;
        pq.erase(*it) ;

        set<LL>::iterator it2 ;
        for(int i=0;i<v[u.id].size();i++)
        {
            pq.insert((Q){v[u.id][i].ed,(LL)u.dis+v[u.id][i].dis}) ;
            st.insert((LL)u.dis+v[u.id][i].dis) ;
            while(st.size()>num+1) { it2=st.end() ; it2-- ; st.erase(*it2) ; }
            it2=st.end() ; it2-- ;
            while(!pq.empty())
            {
                it=pq.end() ; it-- ;
                if(it->dis > (*it2)) pq.erase(it) ;
                else break ;
            }
        }
    }
    return -1 ;
}

main()
{
    int m,st ;
    while(scanf("%d%d%d%d",&n,&m,&k,&st)!=EOF)
    {
        for(int i=1;i<=n;i++) v[i].clear() ;
        while(m--)
        {
            int x,y,dis ; scanf("%d%d%d",&x,&y,&dis) ;
            v[x].push_back((P){y,dis}) ;
            v[y].push_back((P){x,dis}) ;
        }
        printf("%lld\n",dijkstra(st)) ;
    }
}
