#include<bits/stdc++.h>
using namespace std;
main()
{
    int a,b,c,d,e,f,n ; scanf("%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&n) ;
    printf("%s\n",(a+b+c?(a+b+c-1)/5+1:0)+(d+e+f?(d+e+f-1)/10+1:0)<=n?"YES":"NO") ;
}
