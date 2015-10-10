#include<bits/stdc++.h>
using namespace std;

main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int n ; scanf("%d",&n) ;
        int m=1000000 , sum=0 ;
        for(int i=1;i<=n;i++)
        {
            int x ; scanf("%d",&x) ; sum+=x ;
            m=min(m,x) ;
        }
        printf("%d\n",sum-n*m) ;
    }
}
