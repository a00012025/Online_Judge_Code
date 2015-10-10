#include<bits/stdc++.h>
using namespace std;
const int maxn=2000+10,maxl=1000000+10 ;

vector<int> v[maxl] ;

int fa[maxn],n ;
int getfa(int x)
{
    return fa[x]==x ? x : fa[x]=getfa(fa[x]) ;
}

void add_edge(int x,int y,int type)
{ /// type=1 : dif
    if(type==1) fa[getfa(x)]=getfa(y+n) , fa[getfa(y)]=getfa(x+n) ;
    else fa[getfa(x)]=getfa(y) , fa[getfa(x+n)]=getfa(y+n) ;
}

main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        for(int i=0;i<maxl;i++) v[i].clear() ;
        int L ; scanf("%d%d",&n,&L) ;
        for(int i=1;i<=n;i++)
        {
            fa[i]=i ; fa[i+n]=i+n ;
            int x ;
            while(scanf("%d",&x)==1 && x)
                v[x].push_back(i) ;
            while(scanf("%d",&x)==1 && x)
                v[x].push_back(-i) ;
        }

        for(int i=0;i<maxl;i++) if(!v[i].empty())
            for(auto j : v[i]) if(j>0)
                for(auto k : v[i]) if(k<0)
                add_edge(j,-k,1) ;
        for(int i=0;2*i<maxl;i++)
            if(!v[i].empty() && !v[L+1-i].empty())
            for(auto j : v[i]) for(auto k : v[L+1-i])
        {
            if(j>0 && k<0) add_edge(j,-k,0) ;
            if(j<0 && k>0) add_edge(-j,k,0) ;
        }

        bool ok=1 ;
        for(int i=1;i<=n;i++) if(getfa(i)==getfa(n+i))
            {ok=0 ; break ;}
        if(ok) printf("Yes\n") ;
        else printf("No\n") ;
    }
}
