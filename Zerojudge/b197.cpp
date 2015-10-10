#include<stdio.h>
#include<algorithm>
#include<math.h>
#define DB double
using namespace std;
main()
{
    int T,n,x1,y1,x2,y2,s,id ;
    scanf("%d",&T) ;
    while(T--)
    {
        scanf("%d",&n) ;
        DB ans=10000.0 ;
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&s) ;
            x1= (x1>x2) ? (x1-x2) : (x2-x1) ;
            y1= (y1>y2) ? (y1-y2) : (y2-y1) ;
            DB cp= sqrt(x1*x1+y1*y1)*s/x1;
            if (cp<ans)
            {
                ans=cp;
                id=i;
            }
        }
        printf("%d\n",id) ;
    }
}
