#include<bits/stdc++.h>
using namespace std;
struct P{int x,y;};
bool check(P a,P b)
{
    if(a.x>=b.x && a.y>=b.y) return 1 ;
    if(a.x>=b.y && a.y>=b.x) return 1 ;
    return 0 ;
}
P a,b,c ;
main()
{
    scanf("%d%d%d%d%d%d",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y) ;
    for(int i=1;i<a.x;i++)
        if(check((P){i,a.y},b) && check((P){a.x-i,a.y},c))
        {printf("YES\n") ; return 0 ;}
    for(int i=1;i<a.y;i++)
        if(check((P){a.x,i},b) && check((P){a.x,a.y-i},c))
        {printf("YES\n") ; return 0 ;}
    printf("NO\n") ;
}
