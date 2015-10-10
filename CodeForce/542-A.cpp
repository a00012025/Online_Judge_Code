#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=200000+10 ;

struct P
{
    int l,r,id ;
    bool operator < (const P &rhs) const
    {
        return l<rhs.l ;
    }
}a[maxn];

bool cmp1(const P &x,const P &y)
{
    return x.r==y.r ? x.l<y.l : x.r<y.r ;
}

struct Q
{
    int l,r,c,id ;
    bool operator < (const Q &rhs) const
    {
        return l<rhs.l ;
    }
}b[maxn];

bool cmp2(const Q &x,const Q &y)
{
    return x.r==y.r ? x.l<y.l : x.r<y.r ;
}

int ST[16*maxn],ID[16*maxn] ;
void Setmax(int l,int r,int L,int R,int id,int val,int nid)
{
    if(id>=16*maxn){printf("FUCK\n") ; exit(0) ;}
    if(l==L && r==R)
    {
        if(val>ST[id]) ST[id]=val , ID[id]=nid ;
        return ;
    }
    int mid=(L+R)/2 ;
    if(r<=mid) Setmax(l,r,L,mid,2*id,val,nid) ;
    else if(l>mid) Setmax(l,r,mid+1,R,2*id+1,val,nid) ;
    else Setmax(l,mid,L,mid,2*id,val,nid) ,
        Setmax(mid+1,r,mid+1,R,2*id+1,val,nid) ;
}

void query(int L,int R,int id,int pos,int &res,int &resid)
{
    if(id>=16*maxn){printf("FUCK\n") ; exit(0) ;}
    if(L==R){res=ST[id] ; resid=ID[id] ; return ;}
    int mid=(L+R)/2 ;
    if(pos<=mid) query(L,mid,2*id,pos,res,resid) ;
    else query(mid+1,R,2*id+1,pos,res,resid) ;
    if(ST[id]>res) res=ST[id] , resid=ID[id] ;
}

int n,m,SZ ;
int ans1,ans2 ;
LL ans=0LL ;
vector<int> v0 ;
void solve1(int tp)
{
    memset(ST,-1,sizeof(ST)) ;
    memset(ID,0,sizeof(ID)) ;
    for(int i=1,j=1;i<=m;i++)
    {
        while(j<=n && a[j].l<=b[i].l)
            Setmax(a[j].l,a[j].r,0,SZ-1,1,a[j].r,a[j].id) ,
            j++ ;

        int res,resid ;
        query(0,SZ-1,1,b[i].l,res,resid) ;
        if(res>b[i].l)
        {
            res=min(res,b[i].r) ;
            LL val ;
            if(tp==1) val=(LL)(v0[res]-v0[b[i].l])*b[i].c ;
            else val=(LL)(v0[SZ-1-b[i].l]-v0[SZ-1-res])*b[i].c ;
            if(val>ans) ans1=resid , ans2=b[i].id , ans=val ;
        }
    }
}

void solve2()
{
    memset(ST,-1,sizeof(ST)) ;
    memset(ID,0,sizeof(ID)) ;
    for(int i=1,j=1;i<=m;i++)
    {
        while(j<=n && a[j].r<=b[i].r)
            Setmax(0,a[j].l,0,SZ-1,1,v0[a[j].r]-v0[a[j].l],a[j].id) ,
            j++ ;

        int res,resid ;
        query(0,SZ-1,1,b[i].l,res,resid) ;
        if(res>0)
        {
            LL val=(LL)res*b[i].c ;
            if(val>ans) ans1=resid , ans2=b[i].id , ans=val ;
        }
    }
}

main()
{
    scanf("%d%d",&n,&m) ;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&a[i].l,&a[i].r) , a[i].id=i ;
        v0.push_back(a[i].l) ;
        v0.push_back(a[i].r) ;
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&b[i].l,&b[i].r,&b[i].c) , b[i].id=i ;
        v0.push_back(b[i].l) ;
        v0.push_back(b[i].r) ;
    }
    sort(v0.begin(),v0.end()) ;
    v0.resize(unique(v0.begin(),v0.end())-v0.begin()) ;
    SZ=v0.size() ;
    for(int i=1;i<=n;i++)
        a[i].l=lower_bound(v0.begin(),v0.end(),a[i].l)-v0.begin() ,
        a[i].r=lower_bound(v0.begin(),v0.end(),a[i].r)-v0.begin() ;
    for(int i=1;i<=m;i++)
        b[i].l=lower_bound(v0.begin(),v0.end(),b[i].l)-v0.begin() ,
        b[i].r=lower_bound(v0.begin(),v0.end(),b[i].r)-v0.begin() ;

    sort(a+1,a+n+1) ;
    sort(b+1,b+m+1) ;
    solve1(1) ;

    sort(a+1,a+n+1,cmp1) ;
    sort(b+1,b+m+1,cmp2) ;
    solve2() ;

    for(int i=1;i<=n;i++)
    {
        int tl=a[i].l , tr=a[i].r ;
        a[i].l=SZ-1-tr , a[i].r=SZ-1-tl ;
    }
    for(int i=1;i<=m;i++)
    {
        int tl=b[i].l , tr=b[i].r ;
        b[i].l=SZ-1-tr , b[i].r=SZ-1-tl ;
    }
    sort(a+1,a+n+1) ;
    sort(b+1,b+m+1) ;
    solve1(2) ;

    if(ans) printf("%I64d\n%d %d\n",ans,ans1,ans2) ;
    else printf("0\n") ;
}
