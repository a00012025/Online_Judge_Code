#include<bits/stdc++.h>
#define DB double
using namespace std;

main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int a,b ; scanf("%d%d",&a,&b) ;
        b-=a ; b*=100 ;

        bool keep= (b>-7*a && b<10*a) ;
        int ans1= b>=0 ? b/a : -((-b)/a) ;
        int ans2= b>=0 ? b%a : (-b)%a ;
        printf("%3d.%02d %s\n",ans1,ans2*100/a,keep?"keep\n":"dispose\n") ;
    }
}
