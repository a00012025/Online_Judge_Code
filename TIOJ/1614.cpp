#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10 ;

int a[maxn],b[maxn] ;
main()
{
    int n,m ; scanf("%d%d",&n,&m) ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
    for(int i=1;i<=m;i++) scanf("%d",&b[i]) ;
    sort(b+1,b+m+1) ;
    int ans=0 ;
    for(int i=1;i<=n;i++)
    {
        int x=lower_bound(b+1,b+m+1,a[i])-b ;
        if(x<=m && b[x]==a[i]) continue ;
        if((m-x+1)%2==0) ans++ ;
    }
    printf("%d\n",ans) ;
}
