#include<bits/stdc++.h>
#define LL long long
using namespace std;

LL f[100] ;
main()
{
    f[0]=f[1]=1 ;
    for(int i=2;i<100;i++) f[i]=f[i-1]+f[i-2] ;
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        LL n ; int i ; scanf("%lld",&n) ;
        if(n<0){printf("iyada~\n") ; continue ;}
        for(i=0;f[i]<=n;i++) ; i-- ;
        int ans=0 ;
        for(int j=i;j>=1;j--) if(f[j]<=n)
            n-=f[j] , ans++ ;
        printf("%d\n",ans) ;
    }
}
