#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=10000000 ;
LL ans[maxn] ;

LL f(int n)
{
    //if(n>=maxn) printf("%d\n",n) ;
    if(n==0) return 0 ;
    if(n<maxn && ans[n]) return ans[n] ;
    return max((LL)n,f(n/2)+f(n/3)+f(n/4)) ;
}

void pre_cal()
{
    ans[0]=0 ;
    for(int i=1;i<maxn;i++) ans[i]=f(i) ;
}

main()
{
    pre_cal() ;
    int n ;
    while(scanf("%d",&n)!=EOF) printf("%lld\n",f(n)) ;
}
