#include<bits/stdc++.h>
#define LL long long
using namespace std;

LL F[200] ;

int solve(int n,int k)
{
    if(n==1) return 0 ;
    if(n==2) return 1 ;
    if(n>92 || F[n-2]>=k) return solve(n-2,k) ;
    return solve(n-1,k-F[n-2]) ;
}

main()
{
    F[1]=F[2]=1LL ;
    for(int i=3;i<=92;i++) F[i]=F[i-1]+F[i-2] ;
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int n,k ; scanf("%d%d",&n,&k) ;
        if(n<=92 && k>F[n]) printf("-1\n") ;
        else printf("%d\n",solve(n,k)) ;
    }
}
