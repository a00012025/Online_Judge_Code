#include<bits/stdc++.h>
#define INF 1000000001
using namespace std;
const int maxn=150001 ;
vector<int> G[2*maxn] ;
vector<int> v[maxn] ;
int d1[2*maxn],d2[2*maxn],n ;

bool vis[2*maxn] ;
void dfs(int x,int *d,int &c)
{
    vis[x]=1 ;
    for(int i=0;i<G[x].size();i++)
    {
        if(!vis[G[x][i]]) d[G[x][i]]=d[x]+1 , dfs(G[x][i],d,c) ;
        else c=d[x]+1 ;
    }
}

main()
{
    int m,p ; scanf("%d%d%d",&n,&m,&p) ;
    while(m--)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        v[x].push_back(y) ;
        v[y].push_back(x) ;
    }

    for(int i=0;i<n;i++)
    {
        int to ;
        if(v[i].size()==1)
        {
            to=v[i][0] ;
            if(v[to][0]==i) G[to].push_back(i+n) ;
            else G[to+n].push_back(i+n) ;
            continue ;
        }

        to=v[i][1] ;
        if(v[to][0]==i && v[to].size()>1) G[to].push_back(i) ;
        else G[to+n].push_back(i) ;

        to=v[i][0] ;
        if(v[to][0]==i && v[to].size()>1) G[to].push_back(i+n) ;
        else G[to+n].push_back(i+n) ;
    }

    int c1=-1 , c2=-1 ;
    for(int i=n;i<2*n;i++) d1[i]=d2[i]=INF ;
    d1[p]=0 ; dfs(p,d1,c1) ;
    memset(vis,0,sizeof(vis)) ;
    d2[p+n]=0 ; dfs(p+n,d2,c2) ;

    int Q ; scanf("%d",&Q) ;
    while(Q--)
    {
        int x ; scanf("%d",&x) ;
        int ans=0 ;
        for(int i=0;i<n;i++)
        {
            if(d1[i+n]==x && c1==-1) ans++ ;
            else if(c1>0 && x>=d1[i+n] && (x-d1[i+n])%c1==0) ans++ ;
            if(d2[i+n]==x && c2==-1) ans++ ;
            else if(c2>0 && x>=d2[i+n] && (x-d2[i+n])%c2==0) ans++ ;
        }
        printf("%d\n",ans) ;
    }
}
