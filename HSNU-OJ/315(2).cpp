#define NDEBUG
#ifdef NDEBUG
#define debugf(...) ((void)0)
#else
#define debugf(...) printf(__VA_ARGS__)
#endif // NDEBUG
#include<bits/stdc++.h>
#define MKP(x,y) make_pair(x,y)
#define F first
#define S second
#define LL long long
#define lowbit(x) (x&(-x))
using namespace std;
typedef pair<int,LL> pil ;
const int maxn=2000000+10 ;
pil operator + (const pil &a,const pil &b){ return (pil){a.F+b.F,a.S+b.S} ; }
pil ST[maxn*6] ;
int bit[2*maxn] ;

int L[maxn],R[maxn] ;
vector<int> tmp ;

int find_in_v(int x)
{
    int l=0 , r=tmp.size() ;
    while(r-l>1)
    {
        int mid=(r+l)/2 ;
        if(tmp[mid]>x) r=mid ;
        else l=mid ;
    }
    return l ;
}

void add(int l,int r,int L,int R,int id,int x,LL y)
{
    if(l>r || l<L || r>R) return ; assert(id<maxn*6) ;
    if(l==L && r==R) {ST[id].F+=x ; ST[id].S+=y ; return ; }
    int mid=(L+R)/2 ;
    if(r<=mid) add(l,r,L,mid,2*id,x,y) ;
    else if(l>mid) add(l,r,mid+1,R,2*id+1,x,y) ;
    else
    {
        add(l,mid,L,mid,2*id,x,y) ;
        add(mid+1,r,mid+1,R,2*id+1,x,y) ;
    }
}

pil query(int l,int r,int id,int pos)
{
    assert(id<maxn*6) ;
    if(l==r) return ST[id] ;
    int mid=(l+r)/2 ;
    if(pos<=mid) return ST[id]+query(l,mid,2*id,pos) ;
    else return ST[id]+query(mid+1,r,2*id+1,pos) ;
}

int n2 ;
LL get_val(int pos)
{
    LL x=(LL)tmp[pos-1] ;
    pil p=query(1,n2,1,pos) ;
        if(pos==6) debugf("%d , %I64d\n",p.F,p.S) ;
    return x*p.F + p.S ;
}

void bit_modify(int pos,int x)
{
    while(pos<=n2) bit[pos]+=x , pos+=lowbit(pos) ;
}

int bit_query(int pos)
{
    int ret=0 ;
    while(pos) ret+=bit[pos] , pos-=lowbit(pos) ;
    return ret ;
}

main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++)
        scanf("%d%d",&L[i],&R[i]) , tmp.push_back(L[i]) , tmp.push_back(R[i]) ;
    sort(tmp.begin(),tmp.end()) ;
    tmp.resize(unique(tmp.begin(),tmp.end())-tmp.begin()) ;
    n2=tmp.size() ; /// 1 ~ n2
    for(int i=1;i<=n;i++) L[i]=find_in_v(L[i])+1 , R[i]=find_in_v(R[i])+1 , debugf("%d,%d\n",L[i],R[i]) ;

    for(int i=1;i<=n;i++)
    {
        add(R[i]+1,n2,1,n2,1,1,(LL)-tmp[R[i]-1] ) ;
        add(1,L[i]-1,1,n2,1,-1,(LL)tmp[L[i]-1] ) ;
        bit_modify(R[i],1) ;
        bit_modify(L[i],1) ;
        bit_modify(1,-1) ;
        int l=1 , r=n2 ;
        while(r-l>1)
        {
            int mid=(r+l)/2 ;
            if(bit_query(mid)>0) r=mid ;
            else l=mid ;
        }
        debugf("i=%d , r=%d\n",i,r) ;
        if(r==2 && bit_query(1)>0) r=1 ;
        printf("%lld\n",get_val(r)) ;
    }
}
