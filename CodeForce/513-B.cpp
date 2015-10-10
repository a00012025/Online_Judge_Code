#include<bits/stdc++.h>
#define LL long long
using namespace std;

int a[100] ;

main()
{
    int n ; LL m ; scanf("%d%I64d",&n,&m) ;
    int l=1 , r=n ; m-- ;
    for(int i=n-2;i>=0;i--)
    {
        if(m >= (1LL<<i)) a[r--]=n-i-1 , m-=(1LL<<i) ;
        else a[l++]=n-i-1 ;
    }
    a[r]=n ;
    for(int i=1;i<=n;i++) printf("%d%c",a[i],i==n?'\n':' ') ;
}
