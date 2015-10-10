#include<stdio.h>
#include<vector>
#include<math.h>
#include<algorithm>
#define INF 1000000000.0
using namespace std;
struct pt{double x,y;}P[100001];
int n ;
bool diag[60][60] ;
double dp[60][60] ;

const double eps=1e-10 ;
int dcmp(double d)
{
    if(fabs(d)<eps) return 0 ;
    else return d<0 ? -1 : 1 ;
}

double dot(const pt &a,const pt &b) {return a.x*b.x+a.y*b.y ;}
double cross(const pt &a,const pt &b) {return a.x*b.y-a.y*b.x ;}

pt operator + (const pt &a,const pt &b) { return (pt){a.x+b.x,a.y+b.y} ; }
pt operator - (const pt &a,const pt &b) { return (pt){a.x-b.x,a.y-b.y} ; }
pt operator * (const pt &a,const double &d) { return (pt){a.x*d,a.y*d} ; }
bool operator == (const pt &a,const pt &b)
    {return dcmp(a.x-b.x)==0 && dcmp(a.y-b.y)==0 ;}

bool on_segment(const pt &p,const pt &p1,const pt &p2)
{
    return dcmp(cross(p1-p,p2-p))==0 && dcmp(dot(p1-p,p2-p))==-1 ;
}

bool segment_proper_inter(const pt &a,const pt &b,const pt &c,const pt &d)
{
    double c1=cross(b-a,c-a) , c2=cross(b-a,d-a) ;
    double c3=cross(d-c,a-c) , c4=cross(d-c,b-c) ;
    return dcmp(c1)*dcmp(c2)<0 && dcmp(c3)*dcmp(c4)<0 ;
}

int in_polygon(const pt &p)
{
    int cnt=0 ;
    for(int i=0;i<n;i++)
    {
        pt &p1=P[i] ;
        pt &p2=P[(i+1)%n] ;
        if(p==p1 || p==p2 || on_segment(p,p1,p2)) return -1 ;
        int k=dcmp(cross(p2-p1,p-p1)) ;
        int d1=dcmp(p1.y-p.y) ;
        int d2=dcmp(p2.y-p.y) ;
        if(k>0 && d1<0 && d2>=0) cnt++ ;
        if(k<0 && d2<0 && d1>=0) cnt-- ;
    }
    if(cnt==0) return 0;
    else return 1;
}

void find_diag(int a,int b)
{
    if(a==(b+1)%n || b==(a+1)%n) {diag[a][b]=diag[b][a]=1 ; return ;}
    for(int i=0;i<n;i++) if(i!=a && i!=b && on_segment(P[i],P[a],P[b]))
        {diag[a][b]=diag[b][a]=0 ; return ;}

    for(int i=0;i<n;i++)
    {
        if(segment_proper_inter(P[a],P[b],P[i],P[(i+1)%n]))
            {diag[a][b]=diag[b][a]=0 ; return ;}
    }
    pt mid=(P[a]+P[b])*0.5 ;
    if(in_polygon(mid)==1) diag[a][b]=diag[b][a]=1 ;
    else diag[a][b]=diag[b][a]=0 ;
}

double area(int i,int j,int k)
{
    double ret=cross(P[j]-P[i],P[k]-P[i]) ;
    if(dcmp(ret)>0) return ret/2.0 ;
    else return (-ret)/2.0 ;
}

main()
{
    int T;
    scanf("%d",&T) ;
    while(T--)
    {
        scanf("%d",&n) ;
        for(int i=0;i<n;i++) scanf("%lf%lf",&P[i].x,&P[i].y) ;
        for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) find_diag(i,j) ;
        for(int len=1;len<n;len++) for(int i=0;i+len<n;i++)
        {
            if(len==1) {dp[i][i+1]=0 ; continue ;}
            int j=i+len ;
            dp[i][j]=INF ;
            if(!diag[i][j]) continue ;
            for(int k=i+1;k<=j-1;k++)
                dp[i][j]=min(dp[i][j],max(area(i,j,k),max(dp[i][k],dp[k][j]))) ;
        }
        printf("%.1lf\n",dp[0][n-1]) ;
    }
}
