#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=1000000+10 ;
bool vis[maxn] ;
int p[maxn],pcnt=0 ;
int val[maxn],sum[maxn] ;
void pre_cal()
{
    for(int i=2;i*i<maxn;i++) if(!vis[i])
        for(int j=i+i;j<maxn;j+=i) vis[j]=1 ;
    for(int i=2;i<maxn;i++) if(!vis[i]) p[++pcnt]=i ;
    for(int i=2;i<maxn;i++)
    {
        int t=i,num=1,ok=1 ;
        for(int j=1;j<=pcnt && vis[t];j++)
            if(t%p[j]==0)
        {
            t/=p[j] ; num*=(-1) ;
            if(t%p[j]==0) {ok=0 ; break ;}
        }
        if(t!=1) num*=(-1) ;
        if(ok) val[i]=num ;
    }
    sum[0]=0 ;
    for(int i=1;i<maxn;i++) sum[i]=sum[i-1]+val[i] ;
}

main()
{
    pre_cal() ;
    //int T ; scanf("%d",&T) ;
    int n ;
    while(scanf("%d",&n)==1 && n>=0)
    {
        //int a,b,d ; scanf("%d%d%d",&a,&b,&d) ;
        if(n==0) {printf("0\n") ; continue ;}
        int a=n,b=n ;
        if(a>b) swap(a,b) ;
        LL ans=(LL) a*b+2 ;
        for(int i=2;i<=a;i++)
        {
            int num1=a/i , num2=b/i ;
            int i2=min(a/(a/i),b/(b/i)) ;
            ans+= ((LL)num1)*((LL)num2)*((LL)sum[i2]-sum[i-1]) ;
            i=i2 ;
        }
        printf("%lld\n",ans) ;
    }
}
