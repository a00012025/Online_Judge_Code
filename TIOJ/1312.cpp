#include<bits/stdc++.h>
using namespace std;
const int maxn=10000+10 ;

int fa[maxn] ;
int getfa(int x)
{
    return fa[x]==x ? x : fa[x]=getfa(fa[x]) ;
}

main()
{
    int n,m ;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=1;i<=n;i++) fa[i]=i ;
        while(m--)
        {
            int x,y ; scanf("%d%d",&x,&y) ;
            x=getfa(x) ; y=getfa(y) ;
            if(x<y) fa[y]=x ;
            else fa[x]=y ;
        }
        int x ; scanf("%d",&x) ;
        printf("%d\n",getfa(x)) ;
    }
}
