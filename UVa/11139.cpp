#define NDEBUG
#ifdef NDEBUG
#define debugf(...) ((void)0)
#else
#define debugf(...) printf(__VA_ARGS__)
#endif
#include<bits/stdc++.h>
#define LL long long
using namespace std;
int sum[130][130] , g[130][130] ;
LL conc[130][130] ;
int gcd(int x,int y)
{
    return y==0 ? x : gcd(y,x%y) ;
}

void get_sum()
{
    for(int i=0;i<121;i++) sum[i][0]=sum[0][i]=0 ;
    for(int i=1;i<121;i++) for(int j=1;j<121;j++)
        g[i][j]=gcd(i,j) ,
        sum[i][j]=sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1]+g[i][j] ;
}

int query(int x1,int y1,int x2,int y2)
{
    return sum[x2][y2]-sum[x2][y1-1]-sum[x1-1][y2]+sum[x1-1][y1-1] ;
}

inline LL C(LL x,int k)
{
    return k==2 ? x*(x-1)/2 : (k==3 ? x*(x-1)*(x-2)/6 : x*(x-1)*(x-2)*(x-3)/24);
}

LL cal_1(int x,int y)
{   /// pick : 2*area = 2*i + b - 2
    if(x<=1) return 0LL ;
    LL tot_2a = (x-1)*x*y , tot_b = (x-1)*x + 2*query(1,y,x-1,y) ;
    return ( tot_2a - tot_b + 2*(x-1) )/2 ;
}

LL cal_2(int x,int y)
{   /// pick : 2*area = 2*i + b - 2
    if(y<=1) return 0LL ;
    LL tot_2a = x*y*(y-1)/2 ;
    LL tot_b = (y-1)*g[x][y] + y*(y-1)/2 + query(1,x,y-1,x) ;
    return ( tot_2a - tot_b + 2*(y-1) )/2 ;
}

LL cal_3(int x,int y)
{   /// pick : 2*area = 2*i + b - 2
    if(x<=1 || y<=1) return 0LL ; /// all : (x-1)(y-1) triangles
    LL tot_2a = 2*x*y*(x-1)*(y-1) - (x-1)*x*(y*(y-1)/2) - (y-1)*y*(x*(x-1)/2) ;
    tot_2a -= (x*(x-1)/2)*(y*(y-1)/2) ;
    LL tot_b = (x-1)*query(1,x,y-1,x) + (y-1)*query(1,y,x-1,y) + query(1,1,x-1,y-1) ;
    return (tot_2a - tot_b + 2*(x-1)*(y-1))/2 ;
}

LL cal_2_inside(int x,int y)
{   /// pick : 2*area = 2*i + b - 2
    LL ret=0LL ;
    for(int i=1;i<x;i++)
    {
        int h=i*y/x ; if(h*x==i*y) h-- ;
        if(!h) continue ;
        LL tot_2a = h*x*y - 2*(x-i)*(h*(h+1)/2) ;
        tot_2a -= (x-i)*( ((y-h)+(y-1))*h/2 ) ;
        tot_2a -= i*( h*(h+1)/2 ) ;
        LL tot_b = h*g[x][y] ;
        tot_b += query(x-i,y-h,x-i,y-1)+query(i,1,i,h) ;
        ret += ( tot_2a - tot_b + 2*h )/2 ;
    }
    return ret ;
}

LL concave(int x,int y)
{   /// pick : 2*area = 2*i + b - 2
    LL ret=0LL ;
    ret += 2*( x*y-(x+y+g[x][y])+2 ) ;
    ret += 2*(cal_1(x,y)+cal_1(y,x)) ;
    ret += 4*(cal_2(x,y)+cal_2(y,x)) ;
    ret += 4*cal_2_inside(x,y) ;
    ret += 4*cal_3(x,y) ;
    return ret ;
}

LL ans[121] ;

void pre_cal()
{
    for(LL n=1;n<121;n++)
    {
        ans[n]=C((n+1)*(n+1),4) ;
        ans[n] -= 2*(n+1)*C(n+1,4) ;
        ans[n] -= 2*(n+1)*C(n+1,3)*(n*n+n) ;
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(g[i][j]>=2)
            ans[n] -= (g[i][j]-1)*((n+1)*(n+1)-3)*(n+1-i)*(n+1-j)*2 ;
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(g[i][j]>=3)
            ans[n] += 3*C((LL)g[i][j]-1,2)*(n+1-i)*(n+1-j)*2 ;
        debugf("ans[%lld] = %lld\n",n,ans[n]) ;
    }
    for(int i=1;i<121;i++) for(int j=i;j<121;j++)
        conc[i][j]=conc[j][i]=concave(i,j) ;
    for(int n=1;n<121;n++)
    {
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
            ans[n] += 2*conc[i][j]*((LL)n+1-i)*((LL)n+1-j) ;
        debugf("ans[%d] = %lld\n",n,ans[n]) ;
    }
}

main()
{
    get_sum() ;
    pre_cal() ;
    printf("%I64d\n",conc[3][3]) ;
    int n ;
    while(scanf("%d",&n)==1 && n) printf("%d %lld\n",n,ans[n]) ;
}
