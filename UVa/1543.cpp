#include<bits/stdc++.h>
#define DB double
using namespace std;
const DB INF=10000000.0 , PI=2*acos(0.0) ;
struct pt{DB x,y;}p[50];
pt operator - (const pt &a,const pt &b) {return (pt){a.x-b.x,a.y-b.y} ; }
DB cross(const pt &a,const pt &b) {return a.x*b.y-a.y*b.x ;}
DB area(int a,int b,int c)
{
    return fabs(cross(p[b]-p[a],p[c]-p[a])/2.0) ;
}

DB d[50][50][50] ;
int n,m ;

int num(int i,int j)
{
    if(j>i) return j-i ;
    else return n-i+j ;
}

DB dp(int i,int j,int k)
{
        //printf("%d,%d,%d\n",i,j,k) ;
    if(d[i][j][k]>=0) return d[i][j][k] ;
    if(k==0) return 0.0 ;
    if(num(i,j)-1<k) return -INF ;
    DB &ans=d[i][j][k] ; ans=0.0 ;
    for(int x=(i+1)%n;x!=j;x=(x+1)%n) for(int y=0;y<k;y++)
        ans=max(ans,dp(i,x,y)+dp(x,j,k-1-y)+area(i,x,j)) ;
    return ans ;
}

main()
{
    while(scanf("%d%d",&n,&m)==2 && n+m)
    {
        for(int i=0;i<n;i++)
        {
            DB t ; scanf("%lf",&t) ; t*=2*PI ;
            p[i]=(pt){cos(t),sin(t)} ;
        }
        memset(d,-1,sizeof(d)) ;
        DB ans=0.0 ;
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(i!=j)
        for(int k=0;k<=m-2;k++)
            ans=max(ans,dp(i,j,k)+dp(j,i,m-2-k)) ;
        printf("%.6f\n",ans) ;
    }
}
