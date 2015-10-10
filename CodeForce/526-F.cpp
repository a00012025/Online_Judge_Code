#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=300000+10 ;

int a[maxn] ;
int lmi[maxn],lma[maxn],rmi[maxn],rma[maxn] ;
LL ans=0LL ;
map<int,int> mp ;
void solve(int l,int r)
{
    if(l==r) { ans++ ; return ; }
    int mid=(l+r)/2 ;
    solve(l,mid) ;
    solve(mid+1,r) ;
    for(int i=mid;i>=l;i--)
        lmi[i]=(i==mid ? a[i] : min(a[i],lmi[i+1])) ,
        lma[i]=(i==mid ? a[i] : max(a[i],lma[i+1])) ;
    for(int i=mid+1;i<=r;i++)
        rmi[i]=(i==mid+1 ? a[i] : min(a[i],rmi[i-1])) ,
        rma[i]=(i==mid+1 ? a[i] : max(a[i],rma[i-1])) ;

    for(int i=l;i<=mid;i++)
    {
        int ri=i+lma[i]-lmi[i] ;
        if(ri>mid && ri<=r && rmi[ri]>lmi[i] && rma[ri]<lma[i])
            ans++ ;
    }
    for(int i=mid+1;i<=r;i++)
    {
        int le=i-rma[i]+rmi[i] ;
        if(le<=mid && le>=l && lmi[le]>rmi[i] && lma[le]<rma[i])
            ans++ ;
    }

    mp.clear() ;
    mp[mid+1+rmi[mid+1]]++ ;
    for(int i=mid,L=mid+1,R=mid+1;i>=l;i--)
    {
        while(R+1<=r && rma[R+1]<lma[i])
        {
            R++ ;
            if(R>=L) mp[R+rmi[R]]++ ;
        }
        while(L<=r && rmi[L]>lmi[i])
        {
            L++ ;
            if(L-1<=R) mp[L-1+rmi[L-1]]-- ;
        }
        ans+=mp[lma[i]+i] ;
    }

    mp.clear() ;
    mp[mid+1-rma[mid+1]]++ ;
    for(int i=mid,L=mid+1,R=mid+1;i>=l;i--)
    {
        while(R+1<=r && rmi[R+1]>lmi[i])
        {
            R++ ;
            if(R>=L) mp[R-rma[R]]++ ;
        }
        while(L<=r && rma[L]<lma[i])
        {
            L++ ;
            if(L-1<=R) mp[L-1-rma[L-1]]-- ;
        }
        ans+=mp[i-lmi[i]] ;
    }
}

main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        a[x]=y ;
    }
    solve(1,n) ;
    printf("%lld\n",ans) ;
}
