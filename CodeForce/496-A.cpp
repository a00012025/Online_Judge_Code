#include<bits/stdc++.h>
using namespace std;
const int maxn=100+10 ;

int a[maxn],b[maxn] ;
int n ;
int cal()
{
    int ret=0 ;
    for(int i=1;i<n-1;i++) ret=max(ret,b[i+1]-b[i]) ;
    return ret ;
}

main()
{
    scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
    int ans=2000 ;
    for(int i=2;i<n;i++)
    {
        for(int j=1,cnt=1;j<=n;j++) if(j!=i)
            b[cnt++]=a[j] ;
        ans=min(ans,cal()) ;
    }
    printf("%d\n",ans) ;
}
