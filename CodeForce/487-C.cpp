#include<bits/stdc++.h>
#define LL long long
using namespace std;

bool is_prime(int x)
{
    for(int i=2;i*i<=x;i++) if(x%i==0) return 0 ;
    return 1 ;
}

LL power(int x,int k,int p)
{
    if(k==0) return 1LL ;
    if(k==1) return (LL)x ;
    LL ret=power(x,k/2,p) ;
    if(k%2) return ( ((ret*ret)%p) *x ) % p ;
    else return (ret*ret) % p ;
}

LL inverse(int x,int p)
{
    return power(x,p-2,p) ;
}

main()
{
    int n ; scanf("%d",&n) ;
    if(n!=4 && !is_prime(n)){ printf("NO\n") ; return 0 ; }
    printf("YES\n1\n") ;
    if(n==1) return 0 ;
    if(n==4) { printf("3\n2\n4\n") ; return 0 ; }
    for(int i=1;i<=n-2;i++)
    {
        LL val=inverse(i,n) ;
        val = val*(i+1) % n ;
        printf("%I64d\n",val) ;
    }
    printf("%d\n",n) ;
}
