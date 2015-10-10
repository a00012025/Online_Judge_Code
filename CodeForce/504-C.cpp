#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=100000+10 ;

int n,m,a[maxn],num[maxn],now[maxn] ;

bool check1(int x)
{
    memset(now,0,sizeof(now)) ;
    for(int i=1;i<=x;i++) now[a[i]]++ ;
    if(x>=m)
    {
        for(int i=1;i<=n;i++)
            if( now[i] < (num[i]+1)/2) return 0 ;
        return 1 ;
    }
    else
    {
        if( (n%2) && x==m-1 ) return (num[a[x+1]]%2)&&(check1(x+1)) ;
        for(int i=x+1;n+1-i>i;i++) if(a[i]!=a[n+1-i]) return 0 ;
        return 1 ;
    }
}

main()
{
    scanf("%d",&n) ; m=(1+n)/2 ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) , num[a[i]]++ ;
    int cnt=0 ;
    for(int i=1;i<=n;i++) if(num[i]%2 && ++cnt>1) { printf("0\n") ; return 0 ; }

    int l=0 , r=n ;
    while(r-l>1)
    {
        int mid=(r+l)/2 ;
        if(check1(mid)) r=mid ;
        else l=mid ;
    }

    LL ans=(LL)(n-r+1) ;
    for(int i=1;i<=n;i++) now[i]=num[i] ;
    for(int i=2;i<=n;i++)
    {
        now[a[i-1]]-- ;
        if( i<=n+1-m && now[a[i-1]]<(num[a[i-1]]+1)/2 ) break ;
        if( i>n+1-m && a[i-1]!=a[n+2-i] ) break ;

        r=max(r,i) ;
        if(i-1<=m && a[i-1]!=a[n+2-i]) r=max(r,n+2-i) ;
        ans+=(LL)(n-r+1) ;
    }
    printf("%I64d\n",ans) ;
}
