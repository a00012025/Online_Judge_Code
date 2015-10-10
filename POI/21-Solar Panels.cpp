#include<bits/stdc++.h>
#define INF 1100000000
using namespace std;

int divi(int x,int y)
{
    return y==0 ? INF : x/y ;
}

main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int x0,L1,y0,L2 ;
        scanf("%d%d%d%d",&x0,&L1,&y0,&L2) ;
        L1-=x0 ; L2-=y0 ;
        int ans=1 ;
        for(int d=1;d<=x0 || d<=y0;)
        {
            int d1=min( divi(x0-1,(x0-1)/d) , divi(y0-1,(y0-1)/d) ) ;
            int q1=(x0-1)/d , r1=(x0-1)%d ;
            int q2=(y0-1)/d , r2=(y0-1)%d ;
            if(r1+L1+1>=d && r2+L2+1>=d)
            {
                int x=d1-d ;
                x=min(x, (r1+L1+1-d)/(q1+1) ) ;
                x=min(x, (r2+L2+1-d)/(q2+1) ) ;
                ans=max(ans,d+x) ;
            }
            d=d1+1 ;
        }
        printf("%d\n",ans) ;
    }
}
