#include<bits/stdc++.h>
#define DB double
using namespace std;
const int maxn=1000000+10 ;
struct bigN
{
    DB t ;
    int exp ;

    bigN operator * (int x)
    {
        bigN c=*this ;
        c.t*=x ;
        while(c.t>=10) c.t/=10 , c.exp++ ;
        return c ;
    }

    bigN operator / (int x)
    {
        bigN c=*this ;
        c.t/=x ;
        while(c.t<1) c.t*=10.0 , c.exp--  ;
        return c ;
    }
}a[maxn];

main()
{
    a[1].t=1.0 , a[1].exp=0 ;
    for(int i=2;i<maxn;i++)
        a[i]= (a[i-1]*(4*i-2))/(i+1) ;
    int n ;
    while(scanf("%d",&n)==1 && n)
        printf("%.3fE+%d\n",a[n].t,a[n].exp) ;
}
