#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10 ;

struct P{int x,y;};
int dis(const P &a,const P &b)
{
    int ret=0 ;
    ret+= a.x>=b.x ? a.x-b.x : b.x-a.x ;
    ret+= a.y>=b.y ? a.y-b.y : b.y-a.y ;
    return ret ;
}

P a[maxn] ;
main()
{
    freopen("marathon.in","r",stdin) ;
    freopen("marathon.out","w",stdout) ;
    int n,tot=0 ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&a[i].x,&a[i].y) ;
        if(i>1) tot+=dis(a[i-1],a[i]) ;
    }

    int ans=0 ;
    for(int i=2;i<n;i++) ans=max(ans,
        dis(a[i-1],a[i])+dis(a[i],a[i+1])-dis(a[i-1],a[i+1])) ;
    printf("%d\n",tot-ans) ;
}
