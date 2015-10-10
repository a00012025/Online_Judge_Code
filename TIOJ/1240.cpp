#include<bits/stdc++.h>
using namespace std;
const int maxn=200+10 ;
int d[maxn] ;

main()
{
    int n ; scanf("%d",&n) ;
    int x,sz=0 ;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x) ;
        if(!sz) { d[sz++]=x ; continue ; }
        int id=upper_bound(d,d+sz,x,greater<int>())-d ;
        if(id==sz) sz++ ;
        d[id]=x ;
    }
    printf("%d\n",sz) ;
}
