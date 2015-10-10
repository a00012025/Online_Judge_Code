#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=100000+10 ;

int n,m ;
int a[maxn],b[maxn] ;
LL ti[maxn] ;
bool check(LL t)
{
    for(int i=1;i<=n;i++) b[i]=a[i] ;
    for(int i=1;i<=m;i++) ti[i]=t ;
    ti[1]-- ;
    for(int i=1,j=1;i<=n && j<=m;)
    {
        if(ti[j]<0) break ;
        if(ti[j]>b[i]) ti[j]-=b[i]+1 , b[i]=0 , i++ ;
        else if(ti[j]==b[i]) b[i]=0 , i++ , j++ , ti[j]-=i ;
        else b[i]-=ti[j] , j++ , ti[j]-=i ;
    }
    for(int i=1;i<=n;i++) if(b[i]) return 0 ;
    return 1 ;
}

main()
{
    scanf("%d%d",&n,&m) ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
    LL l=0,r=1LL<<60 ;
    while(r-l>1)
    {
        LL mid=(r+l)/2 ;
        if(check(mid)) r=mid ;
        else l=mid ;
    }
    printf("%I64d\n",r) ;
}
