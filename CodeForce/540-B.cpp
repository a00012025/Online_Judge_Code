#include<bits/stdc++.h>
using namespace std;
const int maxn=2000+10 ;

int a[maxn] ;
main()
{
    int n,k,M,x,y ; scanf("%d%d%d%d%d",&n,&k,&M,&x,&y) ;
    int cnt=0,sum=0 ;
    for(int i=1;i<=k;i++)
    {
        scanf("%d",&a[i]) ;
        if(a[i]<y) cnt++ ;
        sum+=a[i] ;
    }

    if(cnt>=(n+1)/2) {printf("-1\n") ; return 0;}
    for(int i=k+1;i<=n;i++)
        a[i]=((++cnt<(n+1)/2) ? 1 : y) ,
        sum+=a[i] ;
    if(sum>x) printf("-1\n") ;
    else for(int i=k+1;i<=n;i++) printf("%d%c",a[i],i==n?'\n':' ') ;
}
