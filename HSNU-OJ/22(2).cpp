#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=50000+10 ;
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
        if(vis[i])
        {
            int t=i,num=1,ok=1 ;
            for(int j=1;j<=pcnt && t!=1;j++) if(t%p[j]==0)
            {
                t/=p[j] ; num*=(-1) ;
                if(t%p[j]==0) {ok=0 ; break ;}
            }
            if(ok) val[i]=num ;
        }
        else val[i]=-1 ;
    }
    sum[0]=0 ;
    for(int i=1;i<maxn;i++) sum[i]=sum[i-1]+val[i] ;
}

main()
{
    pre_cal() ;
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int a,b,d ; scanf("%d%d%d",&a,&b,&d) ;
        a=a/d ; b=b/d ;
        if(a>b) swap(a,b) ;
        LL ans=(LL) a*b ;
        for(int i=2;i<=a;i++)
        {
            int num1=a/i , num2=b/i ;
            int i2=min(a/(a/i),b/(b/i)) ;
            ans+= ((LL)num1)*((LL)num2)*((LL)sum[i2]-sum[i-1]) ;
            i=i2 ;
        }
        printf("%I64d\n",ans) ;
    }
}
