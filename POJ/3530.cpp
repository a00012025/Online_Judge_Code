#include<stdio.h>
#include<algorithm>
#define LL long long
#define INF (1LL<<60)
using namespace std;

LL solve(LL a,LL b,LL y,LL M)
{
    if(a==0) return 0 ;
    else if(y*((a-1)/y+1)<=b) return (a-1)/y+1 ;
    else if(M%y==0) return INF ;
    LL r=solve( ((-b)%y+y)%y , ((-a)%y+y)%y , M%y , y ) ;
    return r==INF ? INF : (a+r*M-1)/y+1 ;
}

main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int M,y,a,b ; scanf("%d%d%d%d",&M,&y,&a,&b) ;
        b=min(b,M-1) ;
        if(b<a) printf("-1\n") ;
        else
        {
            LL ans=solve(a,b,y,M) ;
            printf("%lld\n",ans==INF ? -1 : ans) ;
        }
    }
}
