#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=100000+10,maxk=61 ;

vector<LL> bas ; /// basis
vector<LL> tmp(maxn) ;
bool gauss_elim(const vector<LL> &v0,LL val)
{
    if(v0.size()==60)
        for(int i=0;i<60;i++) tmp[i]=2*v0[i]+((val&(1LL<<i)) ? 1 : 0) ; /// 60 x 61
    else for(int i=0;i<v0.size();i++) tmp[i]=2*v0[i] ; /// get basis
    for(int i=0,j=60;j>0;j--)
    {
        int id=-1 ;
        for(int k=i;k<v0.size();k++) if(tmp[k]&(1LL<<j))
            {id=k ; break ;}
        if(id==-1) continue ;
        swap(tmp[i],tmp[id]) ;
        for(int k=id+1;k<v0.size();k++) if(tmp[k]&(1LL<<j))
            tmp[k]^=tmp[i] ;
        i++ ;
    }
    for(int i=0;i<60;i++) if(tmp[i]==1) return 0 ;
    return 1 ;
}

int fa[maxn] ;
LL fad[maxn] ;
int getfa(int x)
{
    if(fa[x]==x) return x ;
    int ret=getfa(fa[x]) ;
    fad[x]^=fad[fa[x]] ;
    return fa[x]=ret ;
}
LL join(int x,int y,LL dis)
{
    int x2=getfa(x) , y2=getfa(y) ;
    if(x2==y2) return fad[x]^fad[y]^dis ;
    fa[y2]=x2 ; fad[y2]=fad[x]^fad[y]^dis ;
    return -1 ;
}

int n ;
struct P{int x,y ; LL dis;};
vector<P> E ;
vector<int> v[maxn] ;
bool vis[maxn] ;
LL goald=-1 ;
void dfs(int x,LL nowd)
{
    if(x==n) goald=nowd ;
    for(auto i : v[x]) if(!vis[i])
    {
        vis[i]=1 ;
        int to=(E[i].x==x ? E[i].y : E[i].x) ;
        LL tmp=join(x,to,E[i].dis) ;
        if(tmp!=-1) bas.push_back(tmp) ;
        dfs(to,nowd^E[i].dis) ;
    }
}

vector<LL> hor(60),nowh(60) ;
main()
{
    int m ; scanf("%d%d",&n,&m) ;
    for(int i=0;i<m;i++)
    {
        int x,y ; LL dis ; scanf("%d%d%lld",&x,&y,&dis) ;
        E.push_back((P){x,y,dis}) ;
        v[x].push_back(i) ;
        v[y].push_back(i) ;
    }
    for(int i=1;i<=n;i++) fa[i]=i ;
    dfs(1,0) ;

    gauss_elim(bas,0) ;
    bas=tmp ;
    while(!bas.back()) bas.pop_back() ;
    for(auto &i : bas) i/=2 ;

    for(int i=0;i<bas.size();i++) for(int j=0;j<60;j++)
        if(bas[i]&(1LL<<j)) hor[j]|=(1LL<<i) ;

    LL ans=0 ;
    for(int i=59;i>=0;i--)
    {
        nowh[i]=hor[i] ;
        bool b=(goald&(1LL<<i)) ;
        if(gauss_elim(nowh,b ? ans : ans^(1LL<<i)))
            ans^=(b ? 0 : (1LL<<i)) ;
        else ans^=(b ? (1LL<<i) : 0) ;
    }
    printf("%lld\n",ans^goald) ;
}

