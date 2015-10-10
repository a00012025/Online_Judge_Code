#include<bits/stdc++.h>
using namespace std;

int fa[50001] ;
int getfa(int x)
{
    return fa[x]==x ? x : fa[x]=getfa(fa[x]) ;
}

int eat[50001],ene[50001] ;
main()
{
    int n,Q ; scanf("%d%d",&n,&Q) ;
    for(int i=1;i<=n;i++) fa[i]=i ;
    memset(eat,0,sizeof(eat)) ;
    memset(ene,0,sizeof(ene)) ;
    int ans=0 ;
    while(Q--)
    {
        int type,a,b ; scanf("%d%d%d",&type,&a,&b) ;
        if(a>n || b>n) { ans++ ; continue ; }
        a=getfa(a) ; b=getfa(b) ;
        if(type==1)
        {
            if(a==b) continue ;
            if(eat[a]==b || ene[a]==b) { ans++ ; continue ; }

            fa[a]=b ;
            int x=eat[a] , y=eat[b] , z=ene[a] , u=ene[b] ;

            if(x&&y) fa[x]=y ;
            if(x&&!y) ene[x]=b , eat[b]=x ;

            if(z&&u) fa[z]=u ;
            if(z&&!u) eat[z]=b , ene[b]=z ;

            if(eat[b]&&ene[b]) eat[eat[b]]=ene[b] , ene[ene[b]]=eat[b] ;
        }
        else
        {
            if(a==b) { ans++ ; continue ; }
            if(eat[a]==b) continue ;
            if(eat[b]==a) { ans++ ; continue ; }
            if(eat[a]==eat[b] && eat[a]) { ans++ ; continue ; }
            if(ene[a]==ene[b] && ene[a]) { ans++ ; continue ; }
            if(eat[a]==ene[b] && eat[a]) { ans++ ; continue ; }

            int x=eat[a] , y=eat[b] , z=ene[a] , u=ene[b] ;
            eat[a]=b ; ene[b]=a ;
            if(x) fa[x]=b ;
            if(u) fa[u]=a ;
            if(y&&z) fa[y]=z , eat[b]=z , ene[z]=b ;
            if(y&&!z) eat[y]=a , ene[a]=y ;
            if(!y&&z) eat[b]=z , ene[z]=b ;
        }
    }
    printf("%d\n",ans) ;
}
