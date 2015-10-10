#include<bits/stdc++.h>
#define INF 1000000001
using namespace std;
const int maxn=100000+10 ;

int a[maxn] ;
main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
    sort(a+1,a+n+1) ;
    int ans=0,sum=0 ;
    for(int i=1;sum<INF && i<=n;i++) if(a[i]>=sum)
        sum+=a[i] , ans++ ;
    printf("%d\n",ans) ;
}
