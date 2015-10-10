#include<bits/stdc++.h>
#define LL long long
#define MOD 1000000007
using namespace std;
LL a[10] ;
main()
{
    int n ; scanf("%lld%lld%d",&a[1],&a[2],&n) ;
    for(int i=3;i<10;i++) a[i]=a[i-1]-a[i-2] ;
    printf("%lld\n",(a[(n-1)%6+1]%MOD+MOD)%MOD) ;
}
