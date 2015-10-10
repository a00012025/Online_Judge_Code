#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
using namespace std;
int n,a[501],b[501],c[501],lev[501];
int inv ;

void mer(int l,int r)
{
    if(l==r) return ;
    int mid=(l+r)/2 ;
    mer(l,mid) ; mer(mid+1,r) ;
    int i=l , j=mid+1 , cnt=l ;
    while(i<=mid || j<=r)
    {
        if(i==mid+1 || (j!=r+1 && lev[b[j]]<lev[b[i]]) )
        {
            c[cnt++]=b[j++] ;
            inv += mid+1-i ;
        }
        else c[cnt++]=b[i++] ;
    }
    for(i=l;i<=r;i++) b[i]=c[i] ;
}

int solve()
{
    inv=0 ;
    mer(2,n) ;
    return inv ;
}

main()
{
    while(scanf("%d",&n)==1 && n)
    {
        for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
        int ans=10000000 ;
        for(int i=1;i<=n;i++)
        {
            b[1]=a[i] ;
            for(int j=2;j<=n;j++) b[j]= j<=i ? a[j-1] : a[j] ;
            for(int j=2;a[i]+j-1<=n;j++) lev[a[i]+j-1]=j ;
            for(int j=n+2-a[i];j<=n;j++) lev[j-n-1+a[i]]=j ;
            ans=min(ans,i-1+solve()) ;

            b[1]=a[i] ; b[n]=a[1] ;
            for(int j=2;j<n;j++) b[j]= j>=i ? a[j+1] : a[j] ;
            ans=min(ans,n+1-i+solve()) ;

            b[1]=a[i] ;
            for(int j=2;j<=n;j++) b[j]= j<=i ? a[j-1] : a[j] ;
            for(int j=2;a[i]-j+1>=1;j++) lev[a[i]-j+1]=j ;
            for(int j=a[i]+1;j<=n;j++) lev[n+a[i]-j+1]=j ;
            ans=min(ans,i-1+solve()) ;

            b[1]=a[i] ; b[n]=a[1] ;
            for(int j=2;j<n;j++) b[j]= j>=i ? a[j+1] : a[j] ;
            ans=min(ans,n+1-i+solve()) ;
        }
        printf("%d\n",ans) ;
    }
}
