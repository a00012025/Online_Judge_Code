#include<bits/stdc++.h>
using namespace std;
main()
{
    char c ;
    int x=0 ;
    while(1)
    {
        c=getchar() ;
        if(c<'0'||c>'9') break ;
        x=(x*10+c-'0')%4 ;
    }
    printf("%d\n",x?0:4) ;
}
