#include<bits/stdc++.h>
using namespace std;

const int mod0=20130721,mod1=21679252,mod2=172848 ;
int a[mod1],b[mod1] ;
main()
{
    a[0]=b[0]=0 ; a[1]=b[1]=1 ;
    for(int i=2;i<mod1;i++)
        a[i]=(a[i-1]+a[i-2])%mod0 ,
        b[i]=(b[i-1]+b[i-2])%mod1 ;
    int n ;
    while(scanf("%d",&n)!=EOF) printf("%d\n",a[b[n%mod2]%mod1]) ;
}
