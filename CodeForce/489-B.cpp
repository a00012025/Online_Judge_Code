#include<bits/stdc++.h>
using namespace std;
int a[200],b[200] ;
main()
{
    int n,m ;
    scanf("%d",&n) ; for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
    scanf("%d",&m) ; for(int i=1;i<=m;i++) scanf("%d",&b[i]) ;
    sort(a+1,a+n+1) ; sort(b+1,b+m+1) ;
    int ans=0 , j=1 ;
    for(int i=1;i<=n;i++)
    {
        if(b[j]>a[i]+1) continue ;
        while(j<=m && b[j]<a[i]-1) j++ ;
        if(j>m) break ;
        if(b[j]<=a[i]+1) {ans++ ; j++ ;}
    }
    printf("%d\n",ans) ;
}
