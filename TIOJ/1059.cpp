#include<bits/stdc++.h>
#define DB double
using namespace std;

int num[10],cost[10] ;

main()
{
    int x,t ; scanf("%d%d",&x,&t) ;

    num[0]= ((int)(t*0.2+0.01)) ;
    num[1]= ((int)(t*0.4+0.01))-num[0] ;
    num[2]= ((int)(t*0.6+0.01))-num[1]-num[0] ;
    num[3]= t-num[0]-num[1]-num[2] ;
    cost[0]= ((int)(x*0.7+0.01)) ;
    cost[1]= ((int)(x*0.8+0.01)) ;
    cost[2]= ((int)(x*0.9+0.01)) ;
    cost[3]= x ;

    int exp= x * ( (int)(t*0.3+0.01) ) ;

    int T,n=0 ; scanf("%d",&T) ;
    while(T--) { int x ; scanf("%d",&x) ; n+=x ; }

    int ans=-exp ;
    for(int i=0;n;i++)
    {
        int k=min(num[i],n) ;
        ans+=k*cost[i] ;
        n-=k ;
    }
    printf("%d\n",ans) ;
}
