#include<bits/stdc++.h>
using namespace std;
main()
{
    int n,a,ans=-1 ; scanf("%d%d",&n,&a) ;
    a*=100 ;
    while(n--)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        x=x*100+y ;
        if(a>=x) ans=max(ans,(a-x)%100) ;
    }
    printf("%d\n",ans) ;
}
