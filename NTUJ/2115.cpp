#include<bits/stdc++.h>
#define DB double
using namespace std;
const int maxn=10000 ;

DB s[maxn] ;
bool check(DB c,DB d,DB k)
{
    int q=int(floor(c/k)) ;
    return k*s[q]+(c-q*k)/(2*q+1) >= d ;
}

DB solve(DB c,DB d)
{
    DB l=0 , r=d ;
    int num=1000 ;
    while(num--)
    {
        DB mid=(r+l)/2 ;
        if(check(c,d,mid)) r=mid ;
        else l=mid ;
    }
    return r ;
}

main()
{
    s[1]=1 ;
    for(int i=2;i<maxn;i++) s[i]=s[i-1]+1.0/(2*i-1) ;
    int T ; scanf("%d",&T) ;
    DB c,d ;
    while(T--) scanf("%lf%lf",&d,&c) , printf("%.12f\n",solve(c,d)) ;
}
