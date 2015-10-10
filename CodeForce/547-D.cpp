#include<bits/stdc++.h>
using namespace std;
const int maxn=200000+10 ;

struct P{int x,y,id;};
bool cmp1(const P &a,const P &b)
{
    return a.x==b.x ? a.y<b.y : a.x<b.x ;
}
bool cmp2(const P &a,const P &b)
{
    return a.y==b.y ? a.x<b.x : a.y<b.y ;
}

P p[maxn],tmp[maxn],tmp2[maxn] ;
int ans[maxn] ;
int x[maxn],y[maxn],tcnt ;

void preprocess()
{
    int i ;
    if(tmp[1].x==tmp[0].x)
        for(i=0;tmp[i+1].x==tmp[i].x;i++) ;
    else
        for(i=0;tmp[i+1].y==tmp[i].y;i++) ;
    for(int j=0;j<tcnt;j++) tmp2[j]=tmp[j] ;
    for(int j=0;j<tcnt;j++) tmp[j]=tmp2[(j+i)%tcnt] ;
}

void process_P()
{
    preprocess() ;
    tmp[tcnt++]=tmp[0] ;
    for(int i=0;i<tcnt-1;)
    {
        int j ;
        if(tmp[i+1].x==tmp[i].x)
            for(j=i+1;j<tcnt && tmp[j].x==tmp[i].x;j++) ;
        else
            for(j=i+1;j<tcnt && tmp[j].y==tmp[i].y;j++) ;
        j-- ;
        if(i==0) ans[tmp[0].id]=1 ;
        ans[tmp[j].id]=3-ans[tmp[i].id] ;
        i=j ;
    }
}

vector<int> v[maxn] ;
int fa[maxn] ;
bool vis[maxn],indfs[maxn] ;
int dfs(int u,int f=-1)
{
    vis[u]=indfs[u]=1 ; fa[u]=f ;
    for(auto i : v[u]) if(i!=f && !ans[i])
    {
        if(indfs[i])
        {
            tcnt=0 ;
            for(int j=u;j!=i;j=fa[j])
                tmp[tcnt++]=(P){x[j],y[j],j} ;
            tmp[tcnt++]=(P){x[i],y[i],i} ;
            process_P() ;
            indfs[u]=0 ; return i ;
        }
        else
        {
            int val=dfs(i,u) ;
            if(val!=-1 && val!=u) {indfs[u]=0 ; return val ;}
            else if(val==u && ans[u]) {indfs[u]=0 ; return -1 ;} /// u has been done
        }
    }
    indfs[u]=0 ; return -1 ;
}

void build_graph(int n)
{
    for(int i=0;i<maxn;i++) v[i].clear() ;
    sort(p+1,p+n+1,cmp1) ;
    for(int i=1;i<n;i++) if(p[i].x==p[i+1].x)
        v[p[i].id].push_back(p[i+1].id) ,
        v[p[i+1].id].push_back(p[i].id) ;
    sort(p+1,p+n+1,cmp2) ;
    for(int i=1;i<n;i++) if(p[i].y==p[i+1].y)
        v[p[i].id].push_back(p[i+1].id) ,
        v[p[i+1].id].push_back(p[i].id) ;
}

void dfs2(int u,int f=-1,int c=1)
{
    ans[u]=c ;
    for(auto i : v[u]) if(i!=f)
    {
        if(ans[i]){printf("FUCK\n") ; exit(0) ;}
        dfs2(i,u,3-c) ;
    }
}

main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&p[i].x,&p[i].y) ;
        p[i].id=i ;
        x[i]=p[i].x ; y[i]=p[i].y ;
    }
    build_graph(n) ;

    for(int i=1;i<=n;i++) if(!vis[i]) dfs(i) ;

    int n2=0 ;
    for(int i=1;i<=n;i++) if(!ans[p[i].id])
        p[++n2]=p[i] ;
    build_graph(n2) ;

    memset(vis,0,sizeof(vis)) ;
    for(int i=1;i<=n;i++) if(!ans[i]) dfs2(i) ;
    for(int i=1;i<=n;i++) printf("%c",ans[i]==1?'b':'r') ;
    printf("\n") ;
}
