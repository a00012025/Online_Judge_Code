#include<bits/stdc++.h>
using namespace std;
const int maxn=10000000+10 ;

int a[maxn] ;

void make_prime()
{
    for(int i=2;i*i<maxn;i++) if(!a[i])
        for(int j=i*i;j<maxn;j+=i)
            a[j]=1 ;
    a[1]=0 ;
    for(int i=2;i<maxn;i++) a[i]=a[i-1]+1-a[i] ;
}

main()
{
    make_prime() ;
    int T,n ; scanf("%d",&T) ;
    while(T--) scanf("%d",&n) , printf("%d\n",a[n]) ;
}
