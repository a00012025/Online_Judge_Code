#include<stdio.h>
#include<algorithm>
using namespace std;
int a[20000][3] ;
int goal[20000] ;
int dx[]={1,1,1,1,0,0,0,0},dy[]={1,0,1,0,1,0,1,0},dz[]={1,1,0,0,1,1,0,0} ;

int MAX(int x,int M,bool ok)
{
    int ret=-1 ;
    for(int i=0;i<8;i++)
    {
        int x2=dx[i]*a[x][0]+dy[i]*a[x][1]+dz[i]*a[x][2] ;
        if(x2<M || (x2==M && ok)) ret=max(ret,x2) ;
    }
    return ret ;
}

main()
{
    int n,tc=0;
    while(scanf("%d",&n)==1 && n)
    {
        for(int i=1;i<=n;i++) for(int j=0;j<3;j++)
        {
            double db ; scanf("%lf",&db) ;
            a[i][j]=(int)(db*100+0.5) ;
        }
        for(int i=1;i<=n;i++) scanf("%d",&goal[i]) ;
        int now=2000000000 ;
        for(int i=1;i<=n;i++)
        {
            bool ok=1 ;
            if(i>=2 && goal[i-1]>goal[i]) ok=0 ;
            now=MAX(goal[i],now,ok) ;
        }
        if(now==-1) printf("Case %d: No solution\n",++tc) ;
        else printf("Case %d: %d.%02d\n",++tc,now/100,now%100) ;
    }
}
