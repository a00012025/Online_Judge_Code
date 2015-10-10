#include<bits/stdc++.h>
#define LL long long
#define f(x) (x?1:-1)
using namespace std;
const int maxn=1000000+10 ;
struct P{int id,val;};
deque<P> dq ;
bool s[maxn] ;
main()
{
    int n,p,q ; LL x,y ; scanf("%d%d%d%I64d%I64d",&n,&p,&q,&x,&y) ;
    for(int i=1;i<=n;i++)
    {
        char c=getchar() ;
        if(c!='+' && c!='-') { i-- ; continue ; }
        s[i]= (c=='+') ;
    }
    int sum=0 ;
    for(int i=1;i<=n;i++)
    {
        sum+=f(s[i]) ;
        while(!dq.empty() && dq.front().val>=sum) dq.pop_front() ;
        dq.push_front((P){i,sum}) ;
    }
    int all=sum ; sum=0 ;

    int k=(q-(p+all))/2 ; LL k2=(LL)(k>=0?k:-k) ;
    LL val= (LL)(k>=0 ? -p-2*k : -p) ;
    LL ans ;

    for(int i=1;i<=n;i++)
    {
        while(!dq.empty() && dq.back().id<i) dq.pop_back() ;
        int mi=dq.back().val-sum ;
        sum+=f(s[i]) ;
        while(!dq.empty() && dq.front().val>=sum+all) dq.pop_front() ;
        dq.push_front((P){i+n,sum+all}) ;

        if(i==1)
        {
            if(mi>=val) ans=x*k2 ;
            else ans=x*(k2+ ((val-mi+1)/2)*2 ) ;
            continue ;
        }

        if(mi>=val) ans=min(ans,x*k2+y*((LL)n+1-i)) ;
        else ans=min(ans,x*(k2+ ((val-mi+1)/2)*2 )+y*((LL)n+1-i)) ;
    }

    printf("%I64d\n",ans) ;
}
