#include<stdio.h>
#include<algorithm>
#define INF 1000000
using namespace std;
int d[101][101] ;
main()
{
    int a,b,tc=0 ;
    while(scanf("%d%d",&a,&b)==2 && a+b)
    {
        for(int i=0;i<=100;i++) for(int j=0;j<=100;j++)
            d[i][j]= (i==j ? 0 : INF) ;
        d[a][b]=1 ;
        while(scanf("%d%d",&a,&b)==2 && a+b) d[a][b]=1 ;
        for(int k=1;k<=100;k++)
            for(int i=1;i<=100;i++)
                for(int j=1;j<=100;j++)
                    d[i][j]=min(d[i][j],d[i][k]+d[k][j]) ;
        double ans=0.0,cnt=0.0 ;
        for(int i=1;i<=100;i++) for(int j=1;j<=100;j++)
            if(d[i][j]!=INF) {ans+=d[i][j] ; if(i!=j) cnt++ ;}
        printf("Case %d: average length between pages = %.3lf clicks\n",++tc,ans/cnt) ;
    }
}
