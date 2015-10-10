#include<bits/stdc++.h>
#define INF 1100000000
using namespace std;
const int maxn=100000+10 ;
void EXIT(){printf("IMPOSSIBLE\n") ; exit(0) ;}

int n,col[maxn] ;
void SUCCESS(int x,int y)
{
    printf("POSSIBLE\n%d %d\n",x,y) ;
    for(int i=1;i<=n;i++) printf("%d",col[i]) ;
    printf("\n") ;
    exit(0) ;
}

int L[maxn],R[maxn] ;
vector<int> v[maxn] ;
void inv(int x,int c)
{
    col[x]=c ;
    for(auto i : v[x]) if(col[i]==c)
        inv(i,3-c) ;
}
void inv(int x){inv(x,3-col[x]) ;}

void dfs(int x,int c,int &l1,int &r1,int &l2,int &r2)
{
    col[x]=c ;
    if(c==1) l1=max(l1,L[x]) , r1=min(r1,R[x]) ;
    else l2=max(l2,L[x]) , r2=min(r2,R[x]) ;
    for(auto i : v[x])
    {
        if(col[i]==-1) dfs(i,3-c,l1,r1,l2,r2) ;
        else if(col[i]==c) EXIT() ;
    }
}

struct P
{
    int l,r,l2,r2,start ;
    bool operator < (const P &rhs) const
    {
        return l==rhs.l ? r<rhs.r : l<rhs.l ;
    }
};

multiset<P> le ;
multiset<int> rir ;
multiset<int,greater<int> > ril ;
P p[maxn] ;
int tcnt,start[maxn] ;
main()
{
    int t,T,m ; scanf("%d%d%d%d",&t,&T,&n,&m) ;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&L[i],&R[i]) ;
        if(L[i]>T) EXIT() ;
    }
    while(m--)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        v[x].push_back(y) ;
        v[y].push_back(x) ;
    }

    memset(col,-1,sizeof(col)) ;
    for(int i=1;i<=n;i++) if(col[i]==-1)
    {
        start[tcnt]=i ;
        if(v[i].empty()) p[tcnt++]=(P){L[i],R[i],-1,-1,-1} ;
        else
        {
            int l1,r1,l2,r2 ;
            l1=l2=-INF ; r1=r2=INF ;
            dfs(i,1,l1,r1,l2,r2) ;
            if(l1>r1 || l2>r2) EXIT() ;
            if(r1>r2) swap(l1,l2) , swap(r1,r2) , inv(i) ;
            p[tcnt++]=(P){l1,r1,l2,r2,i} ;
        }
    }

    int nowl=INF ;
    for(int i=0;i<tcnt;i++) nowl=min(nowl,p[i].r) ;
    for(int i=0;i<tcnt;i++)
    {
        int x=start[i] ;
        if(p[i].l2==-1)
        {
            if(p[i].l<=nowl) col[x]=1 , le.insert(p[i]) ;
            else col[x]=2 ,
                ril.insert(p[i].l) , rir.insert(p[i].r) ;
        }
        else if(p[i].l2<p[i].l)
        {
            if(p[i].l<=nowl)
                le.insert(p[i]) ,
                ril.insert(p[i].l2) ,
                rir.insert(p[i].r2) ;
            else if(nowl>=p[i].l2)
                inv(x) ,
                le.insert((P){p[i].l2,p[i].r2,-2,-2,-1}) ,
                ril.insert(p[i].l) ,
                rir.insert(p[i].r) ;
            else EXIT() ;
        }
        else if(p[i].l<=nowl)
            le.insert((P){p[i].l,p[i].r,-2,-2,-1}) ,
            ril.insert(p[i].l2) ,
            rir.insert(p[i].r2) ;
        else EXIT() ;
    }

    if(ril.empty()) SUCCESS(min(T,nowl),T-min(T,nowl)) ;
    if( (*rir.begin())<(*ril.begin()) ) EXIT() ;
    if(nowl+(*rir.begin()) < t) EXIT() ;
    if(nowl+(*ril.begin()) <= T )
        SUCCESS(nowl,max(t-nowl,*ril.begin())) ;

    while(!le.empty())
    {
        auto it=le.end() ; it-- ;
        if(T-(*ril.begin()) >= it->l)
            SUCCESS(T-(*ril.begin()),*ril.begin()) ;
        if(it->l2 == -2) EXIT() ;

        inv(it->start) ;
        if(it->l2 == -1)
            ril.insert(it->l) ,
            rir.insert(it->r) ,
            le.erase(it) ;
        else
        {
            auto tmp=*it ; le.erase(it) ;
            le.insert((P){tmp.l2,tmp.r2,-2,-2,-1}) ;
            ril.erase(ril.find(tmp.l2)) ;
            rir.erase(rir.find(tmp.r2)) ;
            ril.insert(tmp.l) ;
            rir.insert(tmp.r) ;
        }
        if( (*rir.begin())<(*ril.begin()) ) EXIT() ;
    }
    EXIT() ;
}
