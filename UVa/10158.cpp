#include<bits/stdc++.h>
using namespace std;
int fa[20001],ene[20001] ;
bool XD=0 ;
int getfa(int x)
{
    return fa[x]==x ? x : fa[x]=getfa(fa[x]) ;
}

main()
{
    int n ;
    scanf("%d",&n) ;
    {
        for(int i=0;i<20000;i++) fa[i]=i , ene[i]=-1 ;
        int type,x,y ;
        while(scanf("%d%d%d",&type,&x,&y)==3)
        {
            if(!type) break ;
            x=getfa(x) ; y=getfa(y) ;
            if(type==1)
            {
                if(ene[x]==y) { printf("-1\n") ; continue ; }
                if(x==y) continue ;
                if(ene[x]!=-1 && ene[y]!=-1)
                {
                    fa[x]=y ; fa[ene[x]]=ene[y] ;
                }
                else if(ene[x]!=-1) fa[y]=x ;
                else fa[x]=y ;
            }
            if(type==2)
            {
                if(x==y) { printf("-1\n") ; continue ; }
                if(y==ene[x] || x==ene[y]) continue ;
                if(ene[x]!=-1 && ene[y]!=-1)
                {
                    fa[x]=ene[y] ;
                    fa[y]=ene[x] ;
                    ene[ene[x]]=ene[y] ;
                    ene[ene[y]]=ene[x] ;
                }
                else if(ene[x]!=-1) fa[y]=ene[x] ;
                else if(ene[y]!=-1) fa[x]=ene[y] ;
                else ene[x]=y , ene[y]=x ;
            }
            if(type==3)
            {
                if(x==y) printf("1\n") ;
                else printf("0\n") ;
            }
            if(type==4)
            {
                if(ene[x]==y) printf("1\n") ;
                else printf("0\n") ;
            }
        }
    }
}
