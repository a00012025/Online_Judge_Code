#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10 ;

vector<int> v[maxn] ;

int anc[20][maxn] ;
int dep[maxn],size[maxn] ;

void dfs(int x,int f)
{
    anc[0][x]=f ; size[x]=1 ;
    for(auto i : v[x]) if(i!=f)
    {
        dep[i]=dep[x]+1 ;
        dfs(i,x) ;
        size[x]+=size[i] ;
    }
}

int n ;
void build()
{
    for(int i=1;i<20;i++) for(int j=1;j<=n;j++)
        anc[i][j]=anc[i-1][anc[i-1][j]] ;
}

int query_fa(int x,int d)
{
    if(!d) return x ;
    for(int i=19;i>=0 && d;i--) if(d&(1<<i))
    {
        x=anc[i][x] ;
        d^=(1<<i) ;
    }
    return x ;
}

int LCA(int x,int y)
{
    if(dep[x]!=dep[y]) return
        dep[x]>dep[y] ? LCA(query_fa(x,dep[x]-dep[y]),y) :
                        LCA(x,query_fa(y,dep[y]-dep[x])) ;
    if(x==y) return x ;
    for(int i=19;i>=0;i--) if(anc[i][x]!=anc[i][y])
        x=anc[i][x] , y=anc[i][y] ;
    return anc[0][x] ;
}

main()
{
    scanf("%d",&n) ;
    for(int i=1;i<n;i++)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        v[x].push_back(y) ;
        v[y].push_back(x) ;
    }
    dep[1]=0 ;
    dfs(1,1) ;
    build() ;
    int Q ; scanf("%d",&Q) ;
    while(Q--)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        int f=LCA(x,y) ;
        if(x==y) printf("%d\n",n) ;
        else if((dep[x]+dep[y])%2) printf("0\n") ;
        else if(dep[x]==dep[y])
        {
            int d=dep[x]-dep[f] ;
            int x1=query_fa(x,d-1) , y1=query_fa(y,d-1) ;
            printf("%d\n",n-size[x1]-size[y1]) ;
        }
        else
        {
            int d=(dep[x]+dep[y])/2-dep[f] ;
            int f1,f2 ;
            if(dep[x]>dep[y]) f1=query_fa(x,d-1) ;
            else f1=query_fa(y,d-1) ;
            f2=anc[0][f1] ;
            printf("%d\n",size[f2]-size[f1]) ;
        }
    }
}
