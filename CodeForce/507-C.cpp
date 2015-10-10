#include<bits/stdc++.h>
#define LL long long
using namespace std;

main()
{
    int h ; LL n ;
    scanf("%d%I64d",&h,&n) ; n-- ;
    n|=(1LL<<h) ;
    LL ans=(LL)h ;
    for(int i=h-1;i>=0;i--)
    {
        bool t1= ( (1LL<<(i+1))&n ) ;
        bool t2= ( (1LL<<i)&n ) ;
        if(t1==t2) ans+=(1LL<<(i+1))-1 ;
    }
    printf("%I64d\n",ans) ;
}
