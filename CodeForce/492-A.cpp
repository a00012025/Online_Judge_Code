#include<bits/stdc++.h>
using namespace std;

main()
{
    int ans=0,now=0,n ; scanf("%d",&n) ;
    while(now<=n)
    {
        now+=(ans+2)*(ans+1)/2 ;
        if(now>n) break ;
        ans++ ;
    }
    printf("%d\n",ans) ;
}
