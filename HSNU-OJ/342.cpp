#include<bits/stdc++.h>
using namespace std;

int n,k ,a[100001] ;

bool check()
{
    for(int i=1;i<=n;i++) if(a[i]>=k) return 1 ;
    return 0 ;
}

main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        scanf("%d%d",&n,&k) ;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
        if(check()) printf("Yes\n") ;
        else printf("No\n") ;
    }
}
