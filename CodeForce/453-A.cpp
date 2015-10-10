#include<bits/stdc++.h>
#define DB double
using namespace std;
const int maxn=100000+10 ;

DB p[maxn] ;
main()
{
    int m,n ; scanf("%d%d",&m,&n) ;
    for(int i=1;i<=m;i++) p[i]=pow(i*1.0/m,n) ;
    for(int i=m;i>=1;i--) p[i]-=p[i-1] ;
    DB ans=0 ;
    for(int i=1;i<=m;i++) ans+=i*p[i] ;
    printf("%.15f\n",ans) ;
}
