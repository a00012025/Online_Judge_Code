#include<bits/stdc++.h>
using namespace std;
int a[100000],n ;

bool solve()
{
    sort(a+1,a+n+1) ;
    for(int i=3;i<=n;i++) if(a[i]+a[i-2]!=2*a[i-1]) return 0 ;
    return 1 ;
}

main()
{
    while(scanf("%d",&n)==1 && n)
    {
        for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
        if(solve()) printf("Yes\n") ;
        else printf("No\n") ;
    }
}
