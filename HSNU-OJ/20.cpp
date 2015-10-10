#include<bits/stdc++.h>
using namespace std;

main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int n ; scanf("%d",&n) ;
        int z=0 ;
        int x,y=0 ; for(int i=1;i<=n;i++)
        {
            scanf("%d",&x) ;
            if(x!=y && i%2==n%2) z^=x-y ;
            y=x ;
        }
        if(z==0) printf("NIE\n") ;
        else printf("TAK\n") ;
    }
}
