#include<bits/stdc++.h>
using namespace std;
main()
{
    int a,b,c,d,x,y ;
    scanf("%d%d%d%d",&a,&b,&c,&d) ;
    x=max(3*a/10,a-a/250*c) , y=max(3*b/10,b-b/250*d) ;
    printf("%s\n",x==y?"Tie":(x<y?"Vasya":"Misha")) ;
}
