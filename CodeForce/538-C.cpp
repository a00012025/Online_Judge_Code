#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10 ;

int p[maxn],h[maxn] ;

main()
{
    int n,m ; scanf("%d%d",&n,&m) ;

    bool ok=1 ;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&p[i],&h[i]) ;
        if(i==1) continue ;
        int x=(h[i]>h[i-1] ? h[i]-h[i-1] : h[i-1]-h[i]) ;
        if(p[i]-p[i-1]<x) ok=0 ;
    }
    if(!ok) {printf("IMPOSSIBLE\n") ; return 0 ;}

    int ma=0 ;
    for(int i=1;i<m;i++)
    {
        int a=h[i] , b=h[i+1] , d=p[i+1]-p[i] ;
        ma=max(ma,max(a,b)) ;
        ma=max(ma,a+(b+d-a)/2) ;
    }
    ma=max(ma,h[1]+p[1]-1) ;
    ma=max(ma,h[m]+n-p[m]) ;
    printf("%d\n",ma) ;
}
