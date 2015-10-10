#include<stdio.h>
#include<stdlib.h>
#include<queue>
#define LL long long
#define ULL unsigned long long
using namespace std;
bool a[50001] ;
int p[6000]={0},fac[6000],num[6000],pfac[6000]={0},cnt2,cnt3 ;
queue<int> q ;
struct P{
    ULL x,y ;
    } ans[100000];
int gcd(int x,int y)
{
    while(x!=0 && y!=0)
    {
        if(x>=y) x=x%y ;
        else y=y%x ;
    }
    if(!x) return y ;
    else return x ;
}

void dfs(int i,int now)
{
    if(i==cnt2) fac[++cnt3]=now ;
    else
    {
        int m=1 ;
        for(int j=0;j<=num[i+1];j++)
        {
            dfs(i+1,now*m) ;
            m=m*pfac[i+1] ;
        }
    }
}

main()
{
        //freopen("input.txt","r",stdin) ;
        //freopen("output3.txt","w",stdout) ;
    a[1]=0 ;
    for(int i=2;i<=50000;i++) a[i]=1 ;
    for(int i=2;i<=50000;i++)
    {
        if(!a[i])continue ;
        for(int j=2;i*j<=50000;j++) a[i*j]=0 ;
    }
    int cnt=1 ;
    for(int i=1;i<=50000;i++)
    {
        if(!a[i])continue ;
        p[cnt++]=i ;
    }   // 5133
    int n ;
    while(scanf("%d",&n)!=EOF){
    cnt2=0 ; int m=n ;
    for(int i=1;p[i]!=0;i++)
    {
        if(m%p[i]) continue ;
        cnt=0 ;
        for(;!(m%p[i]);m=m/p[i]) cnt++ ;
        cnt2++ ; pfac[cnt2]=p[i] ; num[cnt2]=cnt ;
    }
    if(m!=1){cnt2++ ; pfac[cnt2]=m ; num[cnt2]=1 ;}
    cnt3=0 ;
    dfs(0,1) ;
    int cnt4=0 ;
    for(int i=1;i<=cnt3;i++)
        for(int j=1;j<=cnt3;j++)
    {
        int u=fac[i],v=fac[j] ;
        if(gcd(u,v)!=1) continue ;
        cnt4++ ;
        ans[cnt4].x=(ULL)n/u*((ULL)u+v) ;
        ans[cnt4].y=(ULL)n/v*((ULL)u+v) ;
    }
    printf("%d\n",cnt4) ;
    for(int i=1;i<=cnt4;i++) printf("%I64u %I64u\n",ans[i].x,ans[i].y) ;
}
}

