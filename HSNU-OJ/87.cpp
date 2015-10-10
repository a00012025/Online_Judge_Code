#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=20000+10 ;

LL ans=0LL ;
int a[maxn],b[maxn],tmp[maxn] ;

void mer(int l,int r)
{
    if(l==r) return ;
    int mid=(l+r)/2 ;
    mer(l,mid) ; mer(mid+1,r) ;
    int i=l , j=mid+1 , cnt=l ;
    while(i<=mid || j<=r)
    {
        if(j==r+1 || (i!=mid+1 && a[i]<=a[j]))
            b[cnt++]=a[i++] ;
        else b[cnt++]=a[j++] , ans+=mid-i+1 ;
    }
    for(i=l;i<=r;i++) a[i]=b[i] ;
}

main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) , tmp[i]=a[i] ;
    mer(1,n) ; printf("%I64d\n",ans) ;
    for(int i=1;i<=n;i++) a[i]=tmp[i] ;
    int Q ; scanf("%d",&Q) ;
    while(Q--)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        if(x>y) swap(x,y) ;
        if(a[x]>a[y]) ans-- ;
        if(a[x]<a[y]) ans++ ;
        for(int i=x+1;i<y;i++)
        {
            if(a[i]>a[x]) ans++ ;
            if(a[i]<a[x]) ans-- ;
            if(a[i]>a[y]) ans-- ;
            if(a[i]<a[y]) ans++ ;
        }
        swap(a[x],a[y]) ;
        printf("%I64d\n",ans) ;
    }
}
