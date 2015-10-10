#include<bits/stdc++.h>
#define LL long long
#define INF 1000000000
#define ABS(x) ((x)>0 ? (x) : (-(x)))
using namespace std;

LL pw[50] ;
main()
{
    int a,n ; scanf("%d%d",&a,&n) ;
    pw[0]=1 ;
    int cnt=0 ;
    for(;pw[cnt]<=INF;cnt++) pw[cnt+1]=pw[cnt]*a ;
    for(int i=cnt;i>=0;i--)
    {
        LL x=n+pw[i] , y=n-pw[i] ;
        if(ABS(x)<ABS(n)) n=x ;
        if(ABS(y)<ABS(n)) n=y ;
    }
    printf("%s\n",n?"NO":"YES") ;
}
