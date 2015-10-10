#include<bits/stdc++.h>
#define DB long double
using namespace std;
const int maxn=300000+10 ;

DB frac[maxn] ;
void get_frac()
{
    frac[0]=(DB)0.0 ;
    for(int i=1;i<maxn;i++) frac[i]=frac[i-1]+log((DB)i) ;
}

DB logC(int a,int b)
{
    return frac[a]-frac[b]-frac[a-b] ;
}

main()
{
    get_frac() ;
    int n,k,tc=0 ;
    while(scanf("%d%d",&n,&k)==2 && n+k)
    {
        if(n==1) { printf("Case %d: %.4Lf\n",++tc,0.0) ; continue ; }
        if(n-1<2*k){printf("Case %d: %.4Lf\n",++tc,(DB)n) ; continue ;}
        DB ans1,ans2,ans3 ;
        if(n<3*k+1) ans1=0.0 ;
        else ans1=log(2)+logC(n-k,2*k+1)-logC(n-1,2*k) , ans1=exp(ans1) ;
        if(n<4*k+2) ans2=0.0 ;
        else ans2=log(2)+logC(n-2*k-1,2*k+1)-logC(n-1,2*k) , ans2=exp(ans2) ;
        if(n<4*k+1) ans3=0.0 ;
        else ans3=log(n-2*k-2)+logC(n-1-2*k,2*k)-logC(n-1,2*k) , ans3=exp(ans3) ;
        printf("Case %d: %.4Lf\n",++tc,n-ans1+ans2-ans3) ;
    }
}
