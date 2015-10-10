#include<bits/stdc++.h>
#define MOD 1000000000
using namespace std;
const int maxn=110000+10 ;
struct P{int x,y,c ;};
int n,m,col[2*maxn] ;
vector<P> edge ;

int fa[2*maxn],ene[2*maxn] ;
int getfa(int x)
{
    return fa[x]==x ? x : fa[x]=getfa(fa[x]) ;
}

bool DSU(int z)
{
    for(int i=1;i<m+n;i++) fa[i]=i , ene[i]=-1 ;
    for(int i=0;i<edge.size();i++)
    {
        int x=getfa(edge[i].x) , y=getfa(edge[i].y) , type=((edge[i].c)^z) ;
        if(type==0)
        {
            if(x==y) continue ;
            if(ene[x]==y) return 0 ;
            if(ene[x]==-1) fa[x]=y ;
            else if(ene[y]==-1) fa[y]=x ;
            else fa[x]=y , fa[ene[x]]=ene[y] ;
        }
        else
        {
            if(x==y) return 0 ;
            if(ene[y]==x) continue ;
            if(ene[x]==-1 && ene[y]==-1) ene[x]=y , ene[y]=x ;
            else if(ene[x]==-1) fa[x]=ene[y] ;
            else if(ene[y]==-1) fa[y]=ene[x] ;
            else fa[ene[x]]=y , fa[ene[y]]=x , ene[x]=y , ene[y]=x ;
        }
    }
    return 1 ;
}
int col2[2*maxn] ;
int solve(int z)
{
    if(!DSU(z)) return 0 ;
    for(int i=2;i<=m+n-1;i++) col2[i]=col[i] ;
    for(int i=2;i<=m+n-1;i++) if(col2[i]!=-1)
    {
        int i2=getfa(i) ;
        if(col2[i2]!=-1 && col2[i2]!=col2[i]) return 0 ;
        col2[i2]=col2[i] ;

        if(ene[i2]!=-1 && col2[ene[i2]]==col2[i2]) return 0 ;
        col2[ene[i2]]=col2[i2]^1 ;
    }

    int ret=1 ;
    for(int i=2;i<=m+n-1;i++) if(fa[i]==i && col2[i]==-1)
    {
        col2[i]=0 ;
        if(ene[i]!=-1) col2[ene[i]]=1 ;
        ret=(ret*2)%MOD ;
    }
    return ret ;
}

main()
{
    int k ; scanf("%d%d%d",&n,&m,&k) ;
    memset(col,-1,sizeof(col)) ;
    while(k--)
    {
        int x,y,c ; scanf("%d%d%d",&x,&y,&c) ;
        if(x==1) { col[y]=c ; continue ; }
        if(y==1) { col[m+x-1]=c ; continue ; }
        if((x%2==0) && (y%2==0)) c^=1 ;
        edge.push_back((P){m+x-1,y,c}) ;
    }
    if(col[1]==-1) printf("%d\n",(solve(0)+solve(1))%MOD) ;
    else printf("%d\n",solve(col[1])) ;
}
