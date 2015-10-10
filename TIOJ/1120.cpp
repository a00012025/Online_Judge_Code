#include<bits/stdc++.h>
using namespace std;

main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        n=(n*6)%40 ;
        int x,y ;
        if(n<=5) x=10+n , y=5 ;
        else if(n<=15) x=15 , y=n ;
        else if(n<=25) x=30-n , y=15 ;
        else if(n<=35) x=5 , y=40-n ;
        else x=n-30 , y=5 ;
        printf("(%d,%d)\n",x,y) ;
    }
}
