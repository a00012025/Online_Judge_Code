#include<bits/stdc++.h>
using namespace std;
int a[2000] ;
main()
{
    int n,l ; scanf("%d%d",&n,&l) ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
    sort(a+1,a+n+1) ;
    double ans=(double)max(a[1],l-a[n]) ;
    for(int i=1;i<n;i++) ans=max(ans,(a[i+1]-a[i])/2.0) ;
    printf("%.10f\n",ans) ;
}
