#include<bits/stdc++.h>
using namespace std;

main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int a,b,n ;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            if(i==2) scanf("%d",&b) ;
            else scanf("%d",&a) ;
            if(i>=2) b/=__gcd(a,b) ;
        }
        if(b==1) printf("Asssss!!\n") ;
        else printf("zzz...\n") ;
    }
}
