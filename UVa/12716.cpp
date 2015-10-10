#include<bits/stdc++.h>
using namespace std;
const int maxn=30000000+5 ;
int a[maxn] ;

void pre_cal()
{
    memset(a,0,sizeof(a)) ;
    for(int i=1;i<maxn;i++) for(int j=2*i;j<maxn;j+=i)
    {
        int k=j-i ;
        if((j^k)==i) a[j]++ ;
    }
    for(int i=1;i<maxn;i++) a[i]+=a[i-1] ;
}

main()
{
    pre_cal() ;
    int T ; scanf("%d",&T) ; int tc=0 ;
    while(T--)
    {
        int n ; scanf("%d",&n) ; printf("Case %d: %d\n",++tc,a[n]) ;
    }
}
