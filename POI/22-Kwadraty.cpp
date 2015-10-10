#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=10000+10 ;
int num[40]={2,3,6,7,8,11,12,15,18,19,22,23,24,27,28,31,
32,33,43,44,47,48,60,67,72,76,92,96,108,112,128} ;
bool d[maxn] ;
int k[maxn],ans[maxn] ;

main()
{
    fill(k,k+maxn,maxn) ;
    d[0]=1 ;
    for(int i=1;i<=100;i++) for(int j=maxn-1;j>=i*i;j--)
        if(!d[j] && d[j-i*i]) d[j]=1 , k[j]=i ;
    for(int i=1;i<=1000;i++) for(int j=i+1;j<maxn;j++)
        if(k[j]<k[i]) { ans[i]=1 ; break ; }
    for(int i=1;i<=1000;i++) ans[i]+=ans[i-1] ;

    LL n ; scanf("%lld",&n) ;
    if(n<=600)
    {
        if(k[n]==maxn) printf("- ") ;
        else printf("%d ",k[n]) ;
        printf("%d\n",ans[n]) ;
        return 0 ;
    }

    LL now=0 , x=0 ;
    for(;now<n;x++,now+=x*x) ; x-- ;
    LL ans1=x+1 ;
    for(int i=0;i<31;i++) if(now-num[i]==n) ans1=x+2 ;
    LL ans2=ans[506]+(x-10)*31 ;
    for(int i=0;i<31;i++) if(now-num[i]>n) ans2-- ;
    printf("%lld %lld\n",ans1,ans2) ;
}
