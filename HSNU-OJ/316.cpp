#include<bits/stdc++.h>
using namespace std;
struct P
{
    int from,to,dis ;
    bool operator < (const P &rhs) const
    {
        return dis<rhs.dis ;
    }
};

int n,k ;
int fa[3000] ;
int getfa(int x)
{
    return fa[x]==x ? x : fa[x]=getfa(fa[x]) ;
}

int x[3000],y[3000],z[3000] ;
int dis(int i,int j)
{
    return max(abs(x[i]-x[j]),max(abs(y[i]-y[j]),abs(z[i]-z[j]))) ;
}

vector<P> edge ;

int kruskal()
{
    for(int i=1;i<=n;i++) fa[i]=i ;
    int num=n ;
    sort(edge.begin(),edge.end()) ;
    for(int i=0;i<edge.size();)
    {
        int j ;
        for(j=i;j<edge.size() && edge[j].dis==edge[i].dis;j++)
        {
            int x=edge[j].from , y=edge[j].to ;
            if(getfa(x)!=getfa(y)) fa[getfa(x)]=getfa(y) , num-- ;
        }
        if(num<k) return edge[i].dis ;
        i=j ;
    }
}

main()
{
    scanf("%d%d",&n,&k) ;
    for(int i=1;i<=n;i++) scanf("%d%d%d",&x[i],&y[i],&z[i]) ;
    for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++)
        edge.push_back((P){i,j,dis(i,j)}) ;
    printf("%d\n",kruskal()) ;
}
