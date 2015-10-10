#include<bits/stdc++.h>
using namespace std;

main()
{
    int a=1,b=2,n ;
    scanf("%d",&n) ;
    if(n<=2){printf("%d\n",n) ; return 0 ;}
    for(int i=3;i<=n;i++)
    {
        int t=b ;
        b=(a+b)%10 ;
        a=t ;
    }
    printf("%d\n",b) ;
}
