#include<bits/stdc++.h>
#define DB long double
using namespace std;

int a,b,c,d ;
bool check(DB val)
{
    DB l1=1e20 , r1=-1e20 ;
    l1=min(l1,(a+val)*(d+val)) ; r1=max(r1,(a+val)*(d+val)) ;
    l1=min(l1,(a-val)*(d+val)) ; r1=max(r1,(a-val)*(d+val)) ;
    l1=min(l1,(a+val)*(d-val)) ; r1=max(r1,(a+val)*(d-val)) ;
    l1=min(l1,(a-val)*(d-val)) ; r1=max(r1,(a-val)*(d-val)) ;
    DB l2=1e20 , r2=-1e20 ;
    l2=min(l2,(b+val)*(c+val)) ; r2=max(r2,(b+val)*(c+val)) ;
    l2=min(l2,(b-val)*(c+val)) ; r2=max(r2,(b-val)*(c+val)) ;
    l2=min(l2,(b+val)*(c-val)) ; r2=max(r2,(b+val)*(c-val)) ;
    l2=min(l2,(b-val)*(c-val)) ; r2=max(r2,(b-val)*(c-val)) ;
    if(l1>r2 || l2>r1) return 0 ;
    else return 1 ;
}

main()
{
    scanf("%d%d%d%d",&a,&b,&c,&d) ;
    DB l=0.0 , r=1e9 ;
    int num=1000 ;
    while(num--)
    {
        DB mid=(r+l)/2 ;
        if(check(mid)) r=mid ;
        else l=mid ;
    }
    double ans=r ;
    printf("%.15f\n",ans) ;
}
