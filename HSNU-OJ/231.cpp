#include<bits/stdc++.h>
using namespace std;
struct P{int from,to,c ;};
vector<P> edge ;

int fa[20001] ;
int getfa(int x)
{
    return fa[x]==x ? x : fa[x]=getfa(fa[x]) ;
}

bool used[100001] ;
main()
{
    int n,m,k ; scanf("%d%d%d",&n,&m,&k) ;
    for(int i=1;i<=m;i++)
    {
        int x,y,c ; scanf("%d%d%d",&x,&y,&c) ;
        edge.push_back((P){x,y,c}) ;
    }

    for(int i=1;i<=n;i++) fa[i]=i ;
    for(int i=0;i<m;i++) if(edge[i].c==1)
    {
        int x=getfa(edge[i].from) , y=getfa(edge[i].to) ;
        if(x!=y) fa[x]=y ;
    }

    int num=0,zero=0 ;
    memset(used,0,sizeof(used)) ;
    for(int i=0;i<m;i++) if(edge[i].c==0)
    {
        zero++ ;
        int x=getfa(edge[i].from) , y=getfa(edge[i].to) ;
        if(x!=y) fa[x]=y , num++ , used[i]=1 ;
        if(num==k) break ;
    }

    for(int i=1;i<=n;i++) if(getfa(1)!=getfa(i)) { printf("no solution\n") ; return 0 ; }

    if(num<k)
    {
        for(int i=1;i<=n;i++) fa[i]=i ;
        for(int i=0;i<m;i++) if(used[i]) fa[getfa(edge[i].from)]=getfa(edge[i].to) ;
        for(int i=0;i<m;i++) if(edge[i].c==0 && !used[i])
        {
            int x=getfa(edge[i].from) , y=getfa(edge[i].to) ;
            if(x!=y) fa[x]=y , num++ , used[i]=1 ;
            if(num==k) break ;
        }
    }
    if(num<k) { printf("no solution\n") ; return 0 ; }

    for(int i=1;i<=n;i++) fa[i]=i ;
    for(int i=0;i<m;i++) if(used[i])
    {
        int x=getfa(edge[i].from) , y=getfa(edge[i].to) ;
        fa[x]=y ;
    }
    for(int i=0;i<m;i++) if(edge[i].c==1)
    {
        int x=getfa(edge[i].from) , y=getfa(edge[i].to) ;
        if(x!=y) fa[x]=y , used[i]=1 ;
    }

    for(int i=0;i<m;i++) if(used[i]) printf("%d %d %d\n",edge[i].from,edge[i].to,edge[i].c) ;
}
