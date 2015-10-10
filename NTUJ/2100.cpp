#include<bits/stdc++.h>
#define SQ(x) ((x)*(x))
#define LL long long
#define DB double
using namespace std;
const int maxn=100+10 ;
const DB PI=2*acos(0.0),eps=1e-7 ;

int n ;
LL x[maxn],y[maxn] ;
bool solve()
{
    scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%lld%lld",&x[i],&y[i]) ;
    x[n+1]=x[1] ; y[n+1]=y[1] ;
    x[n+2]=x[2] ; y[n+2]=y[2] ;

    LL s ;
    for(int i=1;i<=n;i++)
    {
        if(x[i+1]==x[i] && y[i+1]==y[i]) return 0 ;
        if(i==1) s=SQ(x[i+1]-x[i])+SQ(y[i+1]-y[i]) ;
        else if(s!=SQ(x[i+1]-x[i])+SQ(y[i+1]-y[i])) return 0 ;
    }

    LL val1 , val2 ;
    for(int i=1;i<=n;i++)
    {
        LL n1=(x[i+1]-x[i])*(x[i+2]-x[i+1])+
                (y[i+1]-y[i])*(y[i+2]-y[i+1]) ;
        LL n2=(x[i+1]-x[i])*(y[i+2]-y[i+1])-
                (x[i+2]-x[i+1])*(y[i+1]-y[i]) ;
        if(i==1){val1=n1 ; val2=n2 ; continue ;}
        if(val1!=n1 || val2!=n2) return 0 ;
    }

    DB dv1=fabs(s*cos(2*PI/n)) , dv2=fabs(s*sin(2*PI/n)) ;
    if(val1<0) val1=-val1 ;
    if(val2<0) val2=-val2 ;
    return fabs(val1-dv1)<eps && fabs(val2-dv2)<eps ;
}

main()
{
    int T ; scanf("%d",&T) ;
    while(T--) printf("%s\n",solve() ? "+5 Faith" : "No use") ;
}
