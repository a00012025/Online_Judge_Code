#include<bits/stdc++.h>
using namespace std;
const int maxn=20000+10 ;
int n,a[maxn],a2[maxn],b[maxn] ;

int mer(int l,int r,int x)
{
    if(l==r) { return 0 ; }
    int mid=(l+r)/2 , ret=0 ;
    ret+=mer(l,mid,x) ;
    ret+=mer(mid+1,r,x) ;
    for(int i=l,j=mid+1 ; i<=mid ; i++)
    {
        while(j<=r && a2[j]-a2[i]<x) j++ ;
        ret+=r-j+1 ;
    }
    int cnt=l ;
    for(int i=l,j=mid+1;i<=mid||j<=r;)
    {
        if(j==r+1 || (i!=mid+1 && a2[i]<a2[j]))
            b[cnt++]=a2[i++] ;
        else b[cnt++]=a2[j++] ;
    }
    for(int i=l;i<=r;i++) a2[i]=b[i] ;
    return ret ;
}

int cal_num(int x)
{
    for(int i=0;i<=n;i++) a2[i]=a[i] ;
    return mer(0,n,x) ;
}

main()
{
    int k ;
    while(scanf("%d%d",&n,&k)==2 && n+k)
    {
        for(int i=1;i<=n;i++) scanf("%d",&a[i]) , a[i]+=a[i-1] ;
        int l=n*(-10000)-1 , r=n*10000+1 ;
        while(r-l>1)
        {
            int mid=(l+r)/2 ;
            if(cal_num(mid) >= k) l=mid ;
            else r=mid ;
        }
        printf("%d\n",l) ;
    }
}
