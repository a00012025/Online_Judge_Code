#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=100000+10 ;

int a[maxn],b[maxn] ;
int n ;
LL cnt=0LL ;

void mer(int l,int r)
{
    if(l==r) return ;
    int mid=(l+r)/2 ;
    mer(l,mid) ;
    mer(mid+1,r) ;

    int i=l , j=mid+1 , x=l ;
    while(i<=mid || j<=r)
    {
        if(j==r+1 || (i!=mid+1 && a[i]<=a[j]))
            b[x++]=a[i++] ;
        else b[x++]=a[j++] , cnt+=mid-i+1 ;
    }
    for(i=l;i<=r;i++) a[i]=b[i] ;
}

main()
{
    int tc=0 ;
    while(scanf("%d",&n)==1 && n)
    {
        for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
        cnt=0LL ;
        mer(1,n) ;
        printf("Case #%d: %lld\n",++tc,cnt) ;
    }
}
