#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=100000+10 ;

struct P{LL x,y ;}a[maxn],b[maxn];
int deq[maxn] ;

main()
{
    int n,m ;
    scanf("%d",&n) ; n/=2 ;
    scanf("%lld",&a[1].x) ;
    for(int i=2;i<=n;i++)
    {
        LL x,y ; scanf("%lld%lld",&x,&y) ;
        a[i]=(P){a[i-1].x+y,a[i-1].y-x} ;
    }
    scanf("%lld",&a[n+1].x) ;

    scanf("%d",&m) ; m/=2 ;
    scanf("%lld",&b[1].y) ; b[1].y=-b[1].y ;
    for(int i=2;i<=m;i++)
    {
        LL x,y ; scanf("%lld%lld",&x,&y) ;
        b[i]=(P){b[i-1].x+x,b[i-1].y-y} ;
    }

    int l=0 , r=0 ;
    LL ans=0LL ;
    for(int i=1,j=0;i<n;i++)
    {
        LL x=a[i].x , y=a[i].y ;
        while(r>l && b[deq[l]].y>=y) l++ ;
        while(j<m && b[j+1].x<=x )
        {
            j++ ;
            while(r>l &&
                (x-b[deq[r-1]].x)*(y-b[deq[r-1]].y) <=
                (x-b[j].x)*(y-b[j].y) ) r-- ;
            deq[r++]=j ;
        }
        while(r>l+1 &&
            (x-b[deq[l]].x)*(y-b[deq[l]].y) <=
            (x-b[deq[l+1]].x)*(y-b[deq[l+1]].y) ) l++ ;
        if(r>l) ans=max(ans,(x-b[deq[l]].x)*(y-b[deq[l]].y)) ;
    }
    printf("%lld\n",ans) ;
}
