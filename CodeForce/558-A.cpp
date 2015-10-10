#include<bits/stdc++.h>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;
const int maxn=100+10 ;

pii a[maxn] ;
main()
{
    int n; scanf("%d",&n) ;
    for(int i=0;i<n;i++) scanf("%d%d",&a[i].F,&a[i].S) ;
    sort(a,a+n) ;
    int id=lower_bound(a,a+n,pii(0,0))-a ;
    int ans=0,l,r ;
    if(2*id==n) l=0 , r=n-1 ;
    else if(2*id<n) l=0 , r=2*id ;
    else l=2*id-n-1 , r=n-1 ;
    for(int i=l;i<=r;i++) ans+=a[i].S ;
    printf("%d\n",ans) ;
}
