#include<bits/stdc++.h>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;
const int maxn=100000+10 ;

struct qu
{
    int x,y,id ;
    bool operator < (const qu &rhs) const
    {
        return x+y<rhs.x+rhs.y ;
    }
}q[maxn];
int ans[maxn] ;
int le[maxn],ri[maxn] ;
int a[maxn] ;
pii p[maxn] ;
main()
{
    int m,n,Q ; scanf("%d%d%d",&m,&n,&Q) ;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]) ;
        le[i]=ri[i]=i ;
        if(i>1) p[i-1]=(pii){a[i]-a[i-1],i-1} ;
    }
    for(int i=1;i<=Q;i++) scanf("%d%d",&q[i].x,&q[i].y) , q[i].id=i ;
    sort(p+1,p+n) ; sort(q+1,q+Q+1) ;

    int num=n,tot=n ;
    for(int i=1,j=1;i<=Q;i++)
    {
        for(;j<n && p[j].F<=q[i].x+q[i].y+1;j++)
        {
            int x=p[j].S ;
            tot-=a[x]-a[le[x]]+1+a[ri[x+1]]-a[x+1]+1 ;
            tot+=a[ri[x+1]]-a[le[x]]+1 ;
            num-- ;
            le[ri[x+1]]=le[x] ;
            ri[le[x]]=ri[x+1] ;
        }
        ans[q[i].id]=tot+num*(q[i].x+q[i].y) ;
        if(q[i].x>=a[1]) ans[q[i].id]-=q[i].x-a[1]+1 ;
        if(a[n]+q[i].y-1>=m) ans[q[i].id]-=(a[n]+q[i].y-m) ;
    }
    for(int i=1;i<=Q;i++) printf("%d\n",ans[i]) ;
}
