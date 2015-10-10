#include<bits/stdc++.h>
using namespace std;
int a[50001],b[50001] ;
main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int n,m ; scanf("%d%d",&n,&m) ;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
        for(int i=1;i<=m;i++) scanf("%d",&b[i]) ;
        sort(a+1,a+n+1) ;
        sort(b+1,b+m+1) ;
        int ans=0 ;
        for(int i=1,j=1 ; i<=n;i++)
        {
            while(j<=m && b[j]<a[i]) j++ ;
            if(j==m+1) break ;
            ans++ ; j++ ;
        }
        if(ans) printf("%d\n",ans) ;
        else printf("Santa Claus wishes you get AC in the next submission.\n");
    }
}
