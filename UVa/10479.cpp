#define NDEBUG
#ifdef NDEBUG
#define debugf(...) ((void)0)
#else
#define debugf(...) printf(__VA_ARGS__)
#endif // NDEBUG
#include<bits/stdc++.h>
#define ULL unsigned long long
using namespace std;
int S[6][20]={{0,0},{0,0},{0,1,0},{0,2,1},{0,3,0,2,1,1},{0,4,1,0,0,3,0,2,0,2,1,1,1}} ;

int solve(int k,ULL x)
{
    debugf("solve %d,%I64u\n",k,x) ;
    if(k<=5) return S[k][(int)x] ;
    if(x==1) return k-1 ;
    if(x>=(1ULL<<(k-1))-k+2) return 0 ;
    if(x>=(1ULL<<(k-1))-2*k+4) return 1 ;
    ULL now=(ULL)2 ; int t=k-3 ;
    while(now<=x) now+=(1ULL<<t)*(k-2-t) , t-- ;
    t++ ;
    ULL head=(ULL)2 ;
    for(int i=k-3;i>t;i--) head+=(1ULL<<i)*(k-2-i) ;
    ULL newx=x-head+1 ;
    newx= ((newx-1)%(1ULL<<t)) +1 ;
    if(newx==(1ULL<<t)) return t+1 ;
    else return solve(t+1,newx+1) ;
}

main()
{
    ULL n ;
    while(scanf("%llu",&n)==1 && n)
    {
        ULL tmp=n ; int t=0 ;
        while(tmp) {t++ ; tmp/=2 ;}
        t-- ;
        printf("%d\n",solve(t+1,n-(1ULL<<t)+1)) ;
    }
}
