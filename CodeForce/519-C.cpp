#include<bits/stdc++.h>
using namespace std;

int solve(int n,int m)
{
    int ans=0 ;
    if(2*n<=m) return n ;
    ans+=m-n ;
    n-=ans , m-=2*ans ;
    int t=n/3 ;
    ans+=2*t ; n-=3*t ; m-=3*t ;
    if(n==2) ans++ ;
    return ans ;
}

main()
{
    int n,m ; scanf("%d%d",&n,&m) ;
    if(m<n) swap(n,m) ;
    printf("%d\n",solve(n,m)) ;
}
