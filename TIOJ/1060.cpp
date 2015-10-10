#include<bits/stdc++.h>
#define INF 2147483647
using namespace std;
const int maxn=100000 ;
int H[maxn] ;

int h(int x)
{
    if(x>=maxn) abort() ;
    return x<2 ? -1 : H[x] ;
}

int g(int x)
{
    return x<=2 ? x*x-1 : 2 ;
}

int F[maxn] ;
int f(int x)
{
    if(x>=0 && F[x]!=-INF) return F[x] ;
    int ret ;
    if(x==h(x)) ret=1 ;
    else if(x>h(x)) ret=f(x-1)-h(x) ;
    else ret=f(g(x))-g(x) ;
    if(x>=0) F[x]=ret ;
    return ret ;
}

main()
{
    H[0]=H[1]=-1 ;
    for(int i=2;i<maxn;i++) H[i]=2+H[i-1]-H[i-2] ;
    fill(F,F+maxn,-INF) ;
    for(int i=0;i<maxn;i++) f(i) ;

    int n ; scanf("%d",&n) ; printf("%d\n",f(n)) ;
}
