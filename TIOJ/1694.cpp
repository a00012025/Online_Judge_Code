#include<bits/stdc++.h>
#define lowbit(x) (x&-x)
using namespace std;
const int maxn=25000+100 ;
struct P{int l,r,id;};
bool cmp(const P &a,const P &b)
{
    if(a.r!=b.r) return a.r<b.r ;
    if(a.l!=b.l) return a.l<b.l ;
    return a.id<b.id ;
}

int bit[maxn] ;
void add(int x,int val)
{
    while(x<maxn) bit[x]+=val , x+=lowbit(x) ;
}

int query(int l,int r)
{
    l-- ;
    int ret=0 ;
    while(r>0) ret+=bit[r] , r-=lowbit(r) ;
    while(l>0) ret-=bit[l] , l-=lowbit(l) ;
    return ret ;
}

int ans[200010] ;
int a[maxn] ;
void cal(const vector<P> &v)
{
    memset(bit,0,sizeof(bit)) ;
    int now=0 ;
    for(int i=v[0].l;i<=v[0].r;i++)
        now+=query(a[i]+1,maxn-1) , add(a[i],1) ;
    ans[v[0].id]=now ;
    for(int i=1;i<v.size();i++)
    {
        for(int j=v[i-1].r+1;j<=v[i].r;j++)
            now+=query(a[j]+1,maxn-1) ,
            add(a[j],1) ;
        if(v[i-1].l > v[i].l)
        {
            for(int j=v[i-1].l-1;j>=v[i].l;j--)
                now+=query(1,a[j]-1) ,
                add(a[j],1) ;
        }
        else if(v[i-1].l < v[i].l)
        {
            for(int j=v[i-1].l;j<v[i].l;j++)
                now-=query(1,a[j]-1) ,
                add(a[j],-1) ;
        }
        ans[v[i].id]=now ;
    }
}

vector<P> ask[600] ;
main()
{
    int n,Q ; scanf("%d%d",&n,&Q) ;
    int sq=(int)sqrt(n+0.5) ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
    for(int i=1;i<=Q;i++)
    {
        int l,r ; scanf("%d%d",&l,&r) ;
        ask[l/sq].push_back((P){l,r,i}) ;
    }
    for(int i=0;i<600;i++) if(!ask[i].empty())
        sort(ask[i].begin(),ask[i].end(),cmp) ,
        cal(ask[i]) ;
    for(int i=1;i<=Q;i++) printf("%d\n",ans[i]) ;
}
