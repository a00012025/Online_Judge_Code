#include<stdio.h>
#include<stdlib.h>
#include<queue>
#include<set>
#define LL long long
#define ULL unsigned long long
using namespace std;
bool a[50001] ;
int p[6000]={0} ;
queue<int> q ; set<int> s ;
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
main()
{
        //freopen("input.txt","r",stdin) ;
        //freopen("output1.txt","w",stdout) ;
    a[1]=0 ;
    for(int i=2;i<=34000;i++) a[i]=1 ;
    for(int i=2;i<=34000;i++)
    {
        if(!a[i])continue ;
        for(int j=2;i*j<=34000;j++) a[i*j]=0 ;
    }
    int cnt=1 ;
    for(int i=1;i<=34000;i++)
    {
        if(!a[i])continue ;
        p[cnt++]=i ;
    }   // 5133
    int pfac[6000]={0},n ;
    while(scanf("%d",&n)!=EOF){
    int cnt2=0 ; int m=n ;
    for(int i=1;p[i]!=0;i++)
    {
        if(m%p[i]) continue ;
        cnt=0 ;
        for(;!(m%p[i]);m=m/p[i]) cnt++ ;
        cnt2++ ; pfac[cnt2]=p[i] ;
    }
    if(m!=1){cnt2++ ; pfac[cnt2]=m ; }
    while(!q.empty()) q.pop() ;
    q.push(1) ; set<int> fac ; fac.clear() ;
    while(!q.empty())
    {
        int x=q.front() ;
        q.pop() ;
        if(!fac.count(x)) fac.insert(x) ;
        for(int i=1;i<=cnt2;i++)if((ULL)(n) % ((ULL)pfac[i]*x) == 0) q.push(pfac[i]*x);
    }
    int cnt4=0 ;
    set<int>::iterator it1,it2 ;
    for(it1=fac.begin();it1!=fac.end();it1++)
        for(it2=fac.begin();it2!=fac.end();it2++)
    {
        int u=*it1,v=*it2 ;
        if(gcd(u,v)!=1) continue ;
        cnt4++ ;
        ans[cnt4].x=(ULL)n/u*((ULL)u+v) ;
        ans[cnt4].y=(ULL)n/v*((ULL)u+v) ;
    }
    printf("%d\n",cnt4) ;
    //for(int i=1;i<=cnt4;i++) printf("%I64u %I64u\n",ans[i].x,ans[i].y) ;
}
}
