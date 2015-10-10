#include<stdio.h>
#include<string.h>
#include<algorithm>
#define INF 1000000000.0
using namespace std;
int x[105],y[105],n,ch ;
double d[105][105] ;
bool diag[105][105] ;

bool clock_wise(int i,int j,int k) //  i : j -> k
{
    int x1=x[j]-x[i] , y1=y[j]-y[i] ;
    int x2=x[k]-x[i] , y2=y[k]-y[i] ;
    if(x1*y2-x2*y1>0) return 0 ;
    else return 1 ;
}

void find_diag()
{
    int my=-1 , id ;
    for(int i=0;i<n;i++) if(y[i]>my) my=y[ id=i ] ;
    if(clock_wise(id,(id-1+n)%n,(id+1)%n)) ch=1 ;
    else ch=-1 ;

    //printf("%d\n",ch) ;
    for(int i=0;i<n;i++) for(int j=i+1;j<n;j++)
    {
        if(j==i+1 || i==(j+1)%n) diag[i][j]=diag[j][i]=1 ;
        else if(!clock_wise(i,(i+ch+n)%n,(i-ch+n)%n))
            diag[i][j]=diag[j][i]=(!clock_wise(i,(i+ch+n)%n,j)) && (!clock_wise(i,j,(i-ch+n)%n)) ;
        else
            diag[i][j]=diag[j][i]=!( !clock_wise(i,(i-ch+n)%n,j) && !clock_wise(i,j,(i+ch+n)%n) ) ;

        if(!diag[i][j]) d[i][j]=d[j][i]=INF ;
        //printf("diag %d,%d : %d\n",i,j,diag[i][j]) ;
    }
}

double area(int i,int j,int k)
{
    int x1=x[j]-x[i] , y1=y[j]-y[i] ;
    int x2=x[k]-x[i] , y2=y[k]-y[i] ;
        //printf("%d,%d,%d : %d\n",i,j,k,x2*y1-x1*y2) ;
    if(x1*y2>x2*y1) return (x1*y2-x2*y1)/(2.0) ;
    else return (x2*y1-x1*y2)/(2.0) ;
}

double dp(int l,int r)
{
        //printf("%d,%d\n",l,r) ;
    if(r==l+1) return d[l][r]=0.0 ;
    if(d[l][r]!=-1.0) return d[l][r] ;
    d[l][r]=INF ;
    for(int k=l+1;k<=r-1;k++) d[l][r]=min(d[l][r],max(dp(l,k),max(dp(k,r),area(l,k,r)))) ;
    return d[l][r] ;
}

main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        scanf("%d",&n) ;
        for(int i=0;i<n;i++) scanf("%d%d",&x[i],&y[i]) ;
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) d[i][j]=-1.0 ;
        find_diag() ;
        printf("%.1lf\n",dp(0,n-1)) ;
    }
}
