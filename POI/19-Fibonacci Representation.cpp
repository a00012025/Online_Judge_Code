#include<bits/stdc++.h>
#define LL long long
using namespace std;

LL F[100] ;
main()
{
    F[1]=F[2]=1 ;
    for(int i=3;i<100;i++) F[i]=F[i-1]+F[i-2] ;
    int T; scanf("%d",&T) ;
    while(T--)
    {
        LL x ; scanf("%lld",&x) ;
        int ans=0 ;
        while(x)
        {
            int i ;
            for(i=1;F[i]<x;i++) ;
            ans++ ; x=min(F[i]-x,x-F[i-1]) ;
        }
        printf("%d\n",ans) ;
    }
}
