#include<bits/stdc++.h>
using namespace std;
main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int n,sum=0,zero=0 ; scanf("%d",&n) ;
        for(int i=1;i<=n;i++)
        {
            int x ; scanf("%d",&x) ;
            if(!x) zero++ ;
            sum+=x ;
        }
        if(sum>=100 && sum-(n-zero)<100) printf("YES\n") ;
        else printf("NO\n") ;
    }
}
