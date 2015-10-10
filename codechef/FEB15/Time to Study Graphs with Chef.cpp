#include<bits/stdc++.h>
#define LL long long
#define MOD 1000000007
using namespace std;
const int maxn=100000+10 ;
struct P{LL x1 ; int y1 ; LL x2 ; int y2 ; LL val ; };
vector<LL> vec ;
vector<P> event[maxn] ;
P a[maxn] ;

LL power(LL x,LL n)
{
    if(n==0) return 1LL ;
    if(n==1) return x ;
    LL tmp=power(x,n/2) ;
    if(n%2) return (((tmp*tmp)%MOD)*x)%MOD ;
    else return (tmp*tmp)%MOD ;
}

inline int ID(const LL x)
{
    return upper_bound(vec.begin(),vec.end(),x)-vec.begin() ;
}

LL ST[8*maxn],tag[8*maxn] ;

void pushdown(int L,int R,int id)
{
    if(tag[id]==-1) return ;
    int mid=(L+R)/2 ;
    ST[2*id]=tag[id]*((LL)mid-L+1) ; ST[2*id]%=MOD ;
    ST[2*id+1]=tag[id]*((LL)R-mid) ; ST[2*id+1]%=MOD ;
    tag[2*id]=tag[2*id+1]=tag[id] ;
    tag[id]=-1 ;
}

LL query(int l,int r,int L,int R,int id)
{
    if(l==L && r==R) return ST[id] ;
    pushdown(L,R,id) ;
    int mid=(L+R)/2 ;
    if(r<=mid) return query(l,r,L,mid,2*id) ;
    else if(l>mid) return query(l,r,mid+1,R,2*id+1) ;
    else return ( query(l,mid,L,mid,2*id)+query(mid+1,r,mid+1,R,2*id+1) ) % MOD ;
}

void modify(int L,int R,int id,int pos,LL val)
{
    if(L==R) { ST[id]+=val ; ST[id]%=MOD ; return ; }
    pushdown(L,R,id) ;
    int mid=(L+R)/2 ;
    if(pos<=mid) modify(L,mid,2*id,pos,val) ;
    else modify(mid+1,R,2*id+1,pos,val) ;
    ST[id]=ST[2*id]+ST[2*id+1] ; ST[id]%=MOD ;
}

void setval(int L,int R,LL val)
{
    ST[1]=val*((LL)R-L+1) ; ST[1]%=MOD ;
    tag[1]=val ;
    return ;
}

main()
{
    memset(tag,-1,sizeof(tag)) ;
    LL n ; int m,k ; scanf("%lld%d%d",&n,&m,&k) ;
    for(int i=1;i<=k;i++)
        scanf("%lld%d%lld%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2) ,
        a[i].val=-1 ,
        vec.push_back(a[i].x1) ,
        vec.push_back(a[i].x2) ;
    sort(vec.begin(),vec.end()) ;
    vec.resize(unique(vec.begin(),vec.end())-vec.begin()) ;

    for(int i=1;i<=k;i++) event[ID(a[i].x1)].push_back(a[i]) ;

    LL now=0LL ;
    modify(0,m-1,1,0,1LL) ;
    for(int i=1;i<=vec.size();i++)
    {
        LL now2= event[i][0].val==-1 ? event[i][0].x1 : event[i][0].x2 ;
        if(now2!=0)
        {
            LL tmp=ST[1] ;
            tmp*=power(m,now2-now-1) ; tmp%=MOD ;
            now=now2 ;
            if(now==n+1) setval(0,m-1,0) , modify(0,m-1,1,0,tmp) ;
            else setval(0,m-1,tmp) ;
        }

        for(auto j : event[i]) if(j.val!=-1)
            modify(0,m-1,1,j.y2,j.val) ;
        for(auto j : event[i]) if(j.val==-1)
        {
            int id=ID(j.x2) ;
            LL val=query(j.y1,j.y1,0,m-1,1) ;
            event[id].push_back((P){j.x1,j.y1,j.x2,j.y2,val}) ;
        }
    }

    if(now!=n+1)
    {
        LL tmp=ST[1] ;
        tmp*=power(m,n+1-now-1) ; tmp%=MOD ;
        printf("%lld\n",tmp) ;
    }
    else printf("%lld\n",ST[1]) ;
}
