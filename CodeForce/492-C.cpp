#include<bits/stdc++.h>
#define LL long long
#define pii pair<int,int>
#define MKP(x,y) make_pair(x,y)
#define F first
#define S second
using namespace std;

pii a[100001] ;
main()
{
    int n,r,arg ; scanf("%d%d%d",&n,&r,&arg) ;
    LL now=0LL,all=((LL)arg)*((LL)n) ;
    for(int i=1;i<=n;i++)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        now+=x ;
        a[i]=MKP(y,r-x) ;
    }
    sort(a+1,a+n+1) ;
    LL ans=0LL ;
    for(int i=1;i<=n && now<all;i++)
    {
        if(now + a[i].S < all) now+=a[i].S , ans+=((LL)a[i].F)*((LL)a[i].S) ;
        else ans+= (all-now)*((LL)a[i].F) , now=all ;
    }
    printf("%I64d\n",ans) ;
}
