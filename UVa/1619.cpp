#include<stdio.h>
#include<algorithm>
#define LL long long
using namespace std;
LL a[100001],s[100001],ans ;
int ansl,ansr;

int query(int l,int r,int M)
{
    if(l==r) return l ;
    int mid=(l+r)/2 ;
    int id1=query(l,mid,M) ;
    int id2=query(mid+1,r,M) ;
    if(a[id1]!=a[id2]) return a[id1]<a[id2] ? id1 : id2 ;
    else return abs(id1-M)>abs(id2-M) ? id2 : id1 ;
}

bool better(int id,int l,int r)
{
    if(ans==-1) return 1;
    LL val=a[id]*(s[r]-s[l-1]) ;
    if(val != ans) return val>ans ;
    else if(r-l != ansr-ansl) return r-l < ansr-ansl ;
    else return l<ansl ;
}

void solve(int l,int r)
{
    if(l>r) return ;
    if(l==r)
    {
        if(better(l,l,l)) {ans=a[l] ; ansl=ansr=l ; }
        return ;
    }
    int id=query(l,r,(l+r)/2) ;
    if(better(id,l,r)) {ans=(a[id])*(s[r]-s[l-1]) ; ansl=l ; ansr=r ;}
    solve(l,id-1) ; solve(id+1,r) ;
}

main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        s[0]=0LL ;
        for(int i=1;i<=n;i++) {scanf("%lld",&a[i]) ; s[i]=s[i-1]+a[i] ;}
        ans=-1 ;
        solve(1,n) ;
        printf("%lld\n%d %d\n\n",ans,ansl,ansr) ;
    }
}
