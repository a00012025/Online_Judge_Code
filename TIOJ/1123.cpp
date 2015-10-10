#include<bits/stdc++.h>
using namespace std;

bool check(int n,int m,int x,int y)
{
    return ((n-x)^(x-1)^(m-y)^(y-1))!=0 ;
}

int ans,pos,tp ;

void update(int area,int type,int p)
{
    if(area<ans) return ;
    if(area>ans) { ans=area , tp=type , pos=p ; return ; }
    if(type<tp) return ;
    if(p>pos) return ;
    ans=area , tp=type , pos=p ;
}

main()
{
    int n,m,x,y ;
    while(scanf("%d%d%d%d",&n,&m,&x,&y)!=EOF)
    {
        if(!check(n,m,x,y))
            { printf("No winning strategy.\n") ; continue ; }
        ans=0 ;
        for(int i=1;i<x;i++) if(!check(n-i,m,x-i,y))
            update(i*m,2,i) ;
        for(int i=x;i<n;i++) if(!check(i,m,x,y))
            update((n-i)*m,2,i) ;
        for(int i=1;i<y;i++) if(!check(n,m-i,x,y-i))
            update(i*n,1,i) ;
        for(int i=y;i<m;i++) if(!check(n,i,x,y))
            update((m-i)*n,1,i) ;
        if(tp==2) printf("horizontal") ;
        else printf("vertical") ;
        printf(" %d %d\n",pos,ans) ;
    }
}
