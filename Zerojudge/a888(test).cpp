#include<stdio.h>
#include<algorithm>
#define LL long long
using namespace std;
LL cal(int x,int y,int z) // 1<=a<=x , 1<=b<=y , a+b<=z ;
{
    LL ans=(LL)x*y,sub ;
    if(x<y) {int tem=x;x=y;y=tem;} // x>=y (1,1) (z-1,1)
    if(z<=y+1) return ((LL)z*(z-1)/2) ; // (1,1)(z-1,1)(1,y)(z-y,y)
    else if(z<=x+1) return (((LL)2*z-y-1)*y/2) ; //(x,z-x+1) (z-y+1,y) (x,y)
    else if(z<=x+y) return ans-(((LL)x+y-z)*((LL)x+y-z+1)/2) ;
    else return ans ;

}
main()
{
    int n,m,T ;
    scanf("%d",&T) ;
    while(T--)
    {
        scanf("%d %d",&n,&m) ;
        LL ans=0 ;
        if(n>m) {int tem=n ; n=m ; m=tem ;}
        for(int i=1;i<=n-1;i++)
        {
            LL ans1=cal(m-i,m-i,n) ;
            LL ans2=min(i-1,n-i) ;
            ans+=ans1*ans2*2 ;
            if(i*2<=n) ans+=cal(m-i,m-i,n) ;
        }
        printf("%lld\n",ans) ;
    }
}
