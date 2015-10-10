#include<bits/stdc++.h>
#define DB double
using namespace std;
DB logs[100010] ;
main()
{
    logs[1]=0.0 ;
    for(int i=2;i<=100009;i++) logs[i]=logs[i-1]+log(i) ;
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        DB ans=0.0 ;
        int n ; scanf("%d",&n) ;
        ans+=logs[n-2]-2*logs[(n/2)-1] ;
        ans-=(n-2)*log(2) ;
        printf("%.4lf\n",1-exp(ans)) ;
    }
}
