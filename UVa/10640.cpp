#include<bits/stdc++.h>
using namespace std;
main()
{
    int T,tc=0 ; scanf("%d",&T) ;
    while(T--)
    {
        int a,b ; scanf("%d%d",&a,&b) ;
        if(a*3<=b) {printf("Case %d: -1\n",++tc) ; continue ; }
        int ans=10001 ;
        for(int n=1;n<=10000;n++) if(n*(3*a-b)>=a+b)
        {
            int p=3*a*n+a-b*(n+1) , q=2*b*(n+1)-4*n*a ;
            int r=q/p ; if(r*p<q) r++ ;
            ans=min(ans,n+r) ;
        }
        printf("Case %d: %d\n",++tc,ans) ;
    }
}
