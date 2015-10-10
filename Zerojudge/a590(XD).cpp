#include<stdio.h>
#include<math.h>
#include<set>
#include<algorithm>
#define DB double
using namespace std;
const DB eps=1e-9 ;
int dcmp(DB x)
{
    if(fabs(x)<eps) return 0 ;
    return x>0 ? 1 : -1 ;
}
struct pt
{
    DB x,y;
    bool operator < (const pt &rhs) const
    {
        if(dcmp(x-rhs.x)==0 && dcmp(y-rhs.y)==0) return 0 ;
        if(x!=rhs.x) return x<rhs.x ;
        return y<rhs.y ;
    }
};
int n,m ;
main()
{
        freopen("pc.in","r",stdin) ;
        freopen("pc.txt","w",stdout) ;
    int T ; scanf("%d",&T) ; printf("%d\n",T) ;
    pt tmp[100][50] ;
    while(T--)
    {
        scanf("%d",&m) ; printf("%d\n",m) ;
        for(int i=0;i<m;i++)
        {
            int num ; scanf("%d",&num) ; printf("%d",num) ;
            DB M=0.0 ;
            for(int j=1;j<=num;j++)
            {
                scanf("%lf%lf",&tmp[i][j].x,&tmp[i][j].y) ;
                printf(" %.0lf %.0lf",tmp[i][j].x,tmp[i][j].y) ;
            }
            printf("\n") ;
        }

        scanf("%d",&n) ; printf("%d\n",n) ;
        for(int i=0;i<n;i++)
        {
            int num ; scanf("%d",&num) ; printf("%d",num) ;
            DB M=0.0 ;
            for(int j=1;j<=num;j++)
            {
                scanf("%lf%lf",&tmp[i][j].x,&tmp[i][j].y) ;
                printf(" %.0lf %.0lf",tmp[i][j].x,tmp[i][j].y) ;
            }
            printf("\n") ;
        }
    }
}
