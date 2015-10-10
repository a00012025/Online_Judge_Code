#include<bits/stdc++.h>
#define LL long long
#define LD long double
#define DB double
using namespace std;
const int maxn=100000+100 ;
struct P{int from,to,dis;};
vector<int> v[maxn] ;
vector<P> edge ;
int n,fa[maxn] ;
LL mul[maxn] ;
int dfs(int x)
{
    int ret=1 ;
    for(int i=0;i<v[x].size();i++)
    {
        if(edge[v[x][i]].from!=x && edge[v[x][i]].from!=fa[x])
        {
            fa[edge[v[x][i]].from]=x ;
            LL x1=(LL)dfs(edge[v[x][i]].from) ; ret+=(int)x1 ;
            LL x2=(LL)n-x1 ;
            mul[v[x][i]]=x1*x2*(x2-1)+x2*x1*(x1-1) ;
        }
        if(edge[v[x][i]].to!=x && edge[v[x][i]].to!=fa[x])
        {
            fa[edge[v[x][i]].to]=x ;
            LL x1=(LL)dfs(edge[v[x][i]].to) ; ret+=(int)x1 ;
            LL x2=(LL)n-x1 ;
            mul[v[x][i]]=x1*x2*(x2-1)+x2*x1*(x1-1) ;
        }
    }
    return ret ;
}

main()
{
    scanf("%d",&n) ;
    edge.push_back((P){-1,-1,-1}) ;
    for(int i=1;i<n;i++)
    {
        int x,y,dis ; scanf("%d%d%d",&x,&y,&dis) ;
        edge.push_back((P){x,y,dis}) ;
        v[x].push_back(i) ;
        v[y].push_back(i) ;
    }
    fa[1]=1 ;
    dfs(1) ;
    DB ans=0.0 ;
    for(int i=1;i<n;i++) ans+=
        (((DB)mul[i])/((DB)(n-1)*(n-2)))*(((DB)edge[i].dis)/((DB)n))*6.0 ;

    int Q ; scanf("%d",&Q) ;
    while(Q--)
    {
        int id,val ; scanf("%d%d",&id,&val) ;
        int sub=edge[id].dis-val ; edge[id].dis=val ;
        ans-= ( ((DB)sub)/((DB)n) )*( ((DB)mul[id])/((DB)(n-1)*(n-2)) )*6 ;
        printf("%.10f\n",ans) ;
    }
}
