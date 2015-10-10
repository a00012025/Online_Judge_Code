#include<bits/stdc++.h>
#define LL long long
using namespace std;

int x[]={1,-1},y[]={1,-1} ;
main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        LL n,k,d1,d2 ; scanf("%lld%lld%lld%lld",&n,&k,&d1,&d2) ;
        if(n%3){printf("no\n") ; continue ;}
        bool ok=0 ;
        for(int i=0;i<2;i++) for(int j=0;j<2;j++)
        {
            LL a=k-(2*x[i]*d1+y[j]*d2),b,c ;
            if(a%3) continue ;
            a/=3 ;
            b=a+x[i]*d1 , c=b+y[j]*d2 ;
            if(a<0 || b<0 || c<0) continue ;
            if(a<=n/3 && b<=n/3 && c<=n/3) ok=1 ;
        }
        printf("%s\n",ok?"yes":"no") ;
    }
}
