#include<bits/stdc++.h>
#define LL long long
using namespace std;

main()
{
    int T,x,y ; scanf("%d%d%d",&T,&x,&y) ;
    while(T--)
    {
        int n ; scanf("%d",&n) ;
        LL l=0 , r=((LL)x)*((LL)n+1) ;
        while(r-l>1)
        {
            LL mid=(r+l)/2 ;
            if(mid/y + mid/x >= n) r=mid ;
            else l=mid ;
        }
        if(r%x==0 && r%y==0) printf("Both\n") ;
        else if(r%x==0) printf("Vova\n") ;
        else printf("Vanya\n") ;
    }
}
