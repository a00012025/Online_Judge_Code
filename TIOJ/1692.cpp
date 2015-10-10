#include<bits/stdc++.h>
#include"lib1692.h"
using namespace std;
const int maxn=1000+10,maxm=50000+10 ;
struct P{int x,y ;};
vector<P> edge ;
vector<int> v[maxn] ;

struct path{ vector<int> p ; int st,ed ; } v1[2*maxm],v2[2*maxm] ;
int cnt1=0,cnt2=0 ;

int E[maxn] ;
bool vis[maxm] ;
void dfs(int x,int t)
{
    for(int &i=E[x];i<v[x].size();i++) if(!vis[v[x][i]])
    {
        vis[v[x][i]]=1 ;
        int to= (edge[v[x][i]].x==x ? edge[v[x][i]].y : edge[v[x][i]].x) ;
        int tmp=v[x][i] ;
        dfs(to,t) ;

        if(t==1) v1[cnt1].p.push_back(tmp) ;
        else v2[cnt2].p.push_back(tmp) ;

        return ;
    }

    if(t==1) v1[cnt1].st=x ;
    else v2[cnt2].st=x ;
}

bool used[maxn] ;
bool merge(path &a,const path &b)
{
    memset(used,0,sizeof(used)) ;
    for(auto i : a.p) used[edge[i].x]=used[edge[i].y]=1 ;
    int st=-1 ;
    for(auto i : b.p) if(used[edge[i].x])
        { st=edge[i].x ; break ; }
    if(st==-1) return 0 ;

    int sz1=a.p.size() , sz2=b.p.size() ;
    a.p.resize(sz1+sz2) ;

    int id1=0 ;
    if(a.st==st) id1=-1 ;
    else for(int now=a.st;;id1++)
    {
        int to= ( edge[a.p[id1]].x==now ? edge[a.p[id1]].y : edge[a.p[id1]].x ) ;
        if(to==st) break ;
        now=to ;
    }

    for(int i=id1+1;i<sz1;i++) a.p[i+sz2]=a.p[i] ;

    int id2=0 ;
    for(int now=b.st;;id2++)
    {
        int to= ( edge[b.p[id2]].x==now ? edge[b.p[id2]].y : edge[b.p[id2]].x ) ;
        if(to==st)
        {
            for(int i=id2+1;i<id2+1+sz2;i++)
                a.p[i-id2+id1]=b.p[i%sz2] ;
            break ;
        }
        now=to ;
    }
    return 1 ;
}

main()
{
//    freopen("pB.2.in","r",stdin) ;
    Init() ;
    int n,m ; GetVE(n,m) ;
    for(int i=0;i<m;i++)
    {
        int x,y ; Get(x,y) ;
        edge.push_back((P){x,y}) ;
        v[x].push_back(i) ;
        v[y].push_back(i) ;
    }
    for(int i=1;i<=n;i++) if(v[i].size()%2)
    {
        for(int &j=E[i];j<v[i].size() && vis[v[i][j]];j++) ;
        if(E[i]>=v[i].size()) continue ;
        dfs(i,1) ;
        v1[cnt1++].ed=i ;
    }
    for(int i=1;i<=n;i++)
    {
        for(int &j=E[i];j<v[i].size() && vis[v[i][j]];j++) ;
        if(E[i]>=v[i].size()) continue ;
        v2[cnt2].st=-1 ;
        dfs(i,2) ;
        v2[cnt2++].ed=i ;
    }

    for(int i=0;i<cnt2;i++) for(int j=0;j<cnt1;j++)
        if(merge(v1[j],v2[i]))
    {
        for(int k=i;k<cnt2-1;k++) v2[k]=v2[k+1] ;
        cnt2-- ; i-- ;
        break ;
    }

    for(int i=0;i<cnt2;i++) for(int j=i+1;j<cnt2;j++)
        if(merge(v2[i],v2[j]))
    {
        for(int k=j;k<cnt2-1;k++) v2[k]=v2[k+1] ;
        cnt2-- ; j-- ;
        if(i>=cnt2) break ;
    }

    for(int i=0;i<cnt1;i++)
    {
        ReportVst(v1[i].st) ;
        for(auto j : v1[i].p) ReportE(j+1) ;
        ReportVed(v1[i].ed) ;
    }
    for(int i=0;i<cnt2;i++)
    {
        ReportVst(v2[i].st) ;
        for(auto j : v2[i].p) ReportE(j+1) ;
        ReportVed(v2[i].ed) ;
    }
    Final() ;
}

