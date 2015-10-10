#include<bits/stdc++.h>
#define LL long long
using namespace std;

struct P{int id,val;}a[200001],b[200001];

LL num=0LL ;
void mer(int l,int r)
{
    if(l==r) return  ;
    int mid=(l+r)/2 ;
    mer(l,mid) ; mer(mid+1,r) ;
    int i=l , j=mid+1 , cnt=l ;
    while(i<=mid || j<=r)
    {
        if(i==mid+1 || (j!=r+1 && a[j].val<a[i].val))
        {
            num+=(LL)mid-i+1 ;
            b[cnt++]=a[j++] ;
        }
        else b[cnt++]=a[i++] ;
    }
    for(int i=l;i<=r;i++) a[i]=b[i] ;
}

LL add[200001] ;
main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i].val) , a[i].id=i ;
    for(int i=1;i<=n;i++) add[a[i].val]=(LL)(n-i)-(i-1) ;
    mer(1,n) ;
    LL ans=num ;
    for(int i=1;i<n;i++)
    {
        num+=add[i] ;
        ans=min(ans,num) ;
    }
    printf("%lld\n",ans) ;
}
