#include<bits/stdc++.h>
using namespace std;

main()
{
    int n,m,k  ; scanf("%d%d%d",&n,&m,&k) ;
    int x,y ;
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&x) ; if(i==1) { y=x ; continue ; }
        if((int)(abs(x-k)+0.5)==(int)(abs(y-k)+0.5)) printf("Same\n") ;
        if(abs(x-k)<abs(y-k)) printf("Hotter\n") ;
        if(abs(x-k)>abs(y-k)) printf("Colder\n") ;
        y=x ;
    }
}
