#include<bits/stdc++.h>
using namespace std;
const int maxn=1000000+10 ;
int a[maxn] ;
main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) printf("%d%c",a[i],i==n?'\n':' ') ;
}
