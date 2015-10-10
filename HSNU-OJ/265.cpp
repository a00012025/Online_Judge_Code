#include<bits/stdc++.h>
#define LL long long
#define DB double
#define LD long double
using namespace std;
const int maxn=500000+10 ;
const DB eps=1e-7 ;
struct P{int x,y,id ; DB d ;}a[maxn];
bool cmp(const P &p,const P &q){ return p.d<q.d ; }
bool cmp2(const P &p,const P &q){ return p.y<q.y ; }

int ST1[8*20000] ;
LL ST2[8*20000],m ;
void modify(int L,int R,int id,int pos)
{
    if(L==R) { ST1[id]++ ; ST2[id]+=pos ; return ; }
    int mid=(L+R)/2 ;
    if(pos<=mid) modify(L,mid,2*id,pos) ;
    else modify(mid+1,R,2*id+1,pos) ;
    ST1[id]=ST1[2*id]+ST1[2*id+1] ;
    ST2[id]=ST2[2*id]+ST2[2*id+1] ;
}

void query(int L,int R,int id,LL &cost,DB mul,int &ret)
{
    if(L==R)
    {
        DB d=((m/mul)-cost)/((DB)L) ;
        int num=min((int)floor(d+eps),ST1[id]) ;
        ret+=num ;
        cost+=((LL)R)*((LL)num) ;
        return ;
    }
    int mid=(L+R)/2 ;
    if(mul*(cost+ST2[2*id]) <= m+eps)
    {
        ret+=ST1[2*id] ;
        cost+=+ST2[2*id] ;
        query(mid+1,R,2*id+1,cost,mul,ret) ;
    }
    else query(L,mid,2*id,cost,mul,ret) ;
}

P a2[maxn] ;
main()
{
    int n ;
    scanf("%d%I64d",&n,&m) ;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&a[i].x,&a[i].y) ;
        a[i].id=i ;
        a[i].d = ((DB)a[i].x)/((DB)a[i].y)  ;
    }
    sort(a+1,a+n+1,cmp) ;

    LL ansc=m+1 ;
    DB ansd ;
    int ansnum=-1 ;
    for(int i=1;i<=n;i++)
    {
        modify(1,20000,1,a[i].y) ;
        LL cost=0LL ;
        int num=0 ;
        query(1,20000,1,cost,a[i].d,num) ;
        if(num>ansnum) ansnum=num , ansd=a[i].d , ansc=cost*a[i].d ;
        else if(num==ansnum && cost*a[i].d<ansc+eps)
            ansd=a[i].d , ansc=cost*a[i].d ;
    }
    printf("%d\n",ansnum) ;

    int cnt=0 ;
    for(int i=1;i<=n;i++) if(a[i].d<=ansd+eps) a2[++cnt]=a[i] ;
    sort(a2+1,a2+cnt+1,cmp2) ;
    for(int i=1;i<=ansnum;i++) printf("%d\n",a2[i].id) ;
}
