#include<stdio.h>
#include<algorithm>
using namespace std;
typedef struct {int id ; double val ;} P ;
bool cmp(P x,P y)
{
    if(x.val!=y.val) return x.val>y.val ;
    else return x.id<y.id ;
}
P p[2000] ;
main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n) ;
        for(int i=1;i<=n;i++)
        {
            int a,b ;
            scanf("%d %d",&a,&b) ;
            p[i].id=i ; p[i].val=(double(b))/((double)a) ;
        }
        sort(p+1,p+n+1,cmp) ;
        for(int i=1;i<=n;i++)printf("%d%c",p[i].id,i==n? '\n' : ' ') ;
        if(T)printf("\n");
    }
}
