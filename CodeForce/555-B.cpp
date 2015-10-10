#include<bits/stdc++.h>
#define LL long long
#define pli pair<LL,int>
#define F first
#define S second
using namespace std;
const int maxn=200000+10 ;

pli p[maxn] ;
LL l[maxn],r[maxn] ;
struct P
{
    int L,R,id ;
    bool operator < (const P &rhs) const
    {
        return L==rhs.L ? R<rhs.R : L<rhs.L ;
    }
}a[maxn];
int ans[maxn] ;
LL b[maxn] ;

struct Q
{
    int id,val ;
    bool operator < (const Q &rhs) const
    {
        return val>rhs.val ;
    }
};
priority_queue<Q> pq ;
int L[maxn],R[maxn] ;
main()
{
    int n,m ; scanf("%d%d",&n,&m) ;
    if(n-1>m){printf("No\n") ; return 0 ;}
    for(int i=1;i<=n;i++) scanf("%I64d%I64d",&l[i],&r[i]) ;
    for(int i=1;i<=m;i++) scanf("%I64d",&p[i].F) , p[i].S=i , b[i]=p[i].F ;
    sort(p+1,p+m+1) ;
    for(int i=1;i<n;i++)
    {
        LL lo=l[i+1]-r[i] , hi=r[i+1]-l[i] ;
        L[i]=a[i].L=lower_bound(p+1,p+m+1,pli(lo,-1))-p ;
        R[i]=a[i].R=upper_bound(p+1,p+m+1,pli(hi,maxn))-p-1 ;
        if(a[i].R<a[i].L){printf("No\n") ; return 0 ;}
        a[i].id=i ;
    }
    sort(a+1,a+n) ;
    for(int i=1,j=1;j<=m;j++)
    {
        while(i<n && a[i].L<=j)
        {
            pq.push((Q){a[i].id,a[i].R}) ;
            i++ ;
        }
        if(pq.empty()) continue ;
        Q u=pq.top() ; pq.pop() ;
        if(R[u.id]<j){printf("No\n") ; return 0 ;}
        ans[u.id]=p[j].S ;
    }

    printf("Yes\n") ;
    for(int i=1;i<n;i++) printf("%d%c",ans[i],i+1==n?'\n':' ') ;
}
