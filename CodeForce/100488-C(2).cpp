#include<stdio.h>
#include<queue>
#include<stdlib.h>
#include<set>
#define LL long long
#define ULL unsigned long long
using namespace std;
bool a[50001] ;
int p[6000] ;
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
main()
{
        //freopen("input.txt","r",stdin) ;
        //freopen("output2.txt","w",stdout) ;
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
    int pfac[6000]={0},n ;
    while(scanf("%d",&n)!=EOF) {
    int cnt2=0 ; int m=n ;
    for(int i=1;i<=5133;i++)
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
        LL x=q.front() ;
        q.pop() ;
        fac.insert(x) ;
        for(int i=1;i<=cnt2;i++)
            if(((ULL)(n) % ((ULL)pfac[i]*x) == 0)&&!fac.count(pfac[i]*x))
                q.push(pfac[i]*x);
    }
    int cnt4=0 ;
    set<int>::iterator it1 ;
    for(it1=fac.begin();it1!=fac.end();it1++)
    {
        int u=*it1 ;
        set<int> s ; s.clear() ;
        while(!q.empty()) q.pop() ;
        q.push(1) ;
        while(!q.empty())
        {
            int v=q.front() ;
            q.pop() ;
                //printf("%d,%d\n",u,v);
            if(s.count(v)) continue ;
            s.insert(v) ;
            cnt4++ ;
            ans[cnt4].x=(ULL)n/u*((ULL)u+v) ;
            ans[cnt4].y=(ULL)n/v*((ULL)u+v) ;
            for(int i=1;i<=cnt2;i++)
            {
                if(((LL)(n) % ((LL)v*pfac[i])==0) && gcd(u,pfac[i])==1)
                    q.push(v*pfac[i]) ;
            }
        }
    }
    printf("%d\n",cnt4) ;
    for(int i=1;i<=cnt4;i++) printf("%I64u %I64u\n",ans[i].x,ans[i].y) ;
    }
}
