#include<bits/stdc++.h>
using namespace std;
const int maxn=200+10 ;

vector<int> vb[maxn],vg[maxn] ;
main()
{
    int X,Y ; scanf("%d%d",&X,&Y) ;
    int g=__gcd(X,Y) ;
    if(g>=maxn){printf("No\n") ; return 0 ;}

    int n ; scanf("%d",&n) ;
    while(n--)
    {
        int x ; scanf("%d",&x) ;
        vb[x%g].push_back(x/g) ;
    }
    scanf("%d",&n) ;
    while(n--)
    {
        int x ; scanf("%d",&x) ;
        vg[x%g].push_back(x/g) ;
    }
    for(int i=0;i<g;i++) if(vb[i].empty() && vg[i].empty())
        {printf("No\n") ; return 0 ;}
    printf("Yes\n") ;
}
