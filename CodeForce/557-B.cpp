#include<bits/stdc++.h>
#define DB double
using namespace std;
const int maxn=200000+10 ;

int a[maxn] ;
main()
{
    int n,w ; scanf("%d%d",&n,&w) ;
    for(int i=1;i<=2*n;i++) scanf("%d",&a[i]) ;
    sort(a+1,a+2*n+1) ;
    DB mi=w/3.0/n ;
    for(int i=1;i<=n;i++) mi=min(mi,a[i]*1.0) ;
    for(int i=n+1;i<=2*n;i++) mi=min(mi,a[i]*0.5) ;
    printf("%.10f\n",mi*3*n) ;
}
