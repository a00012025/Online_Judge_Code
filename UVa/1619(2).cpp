#include<stdio.h>
#include<deque>
#include<algorithm>
#define LL long long
using namespace std;
struct P {LL m,sum ; int id; };
int n,ansl,ansr ;
LL a[100001],ans ;

bool better(LL val,int l,int r)
{
    if(ans==-1) return 1;
    if(val != ans) return val>ans ;
    if(r-l != ansr-ansl) return r-l<ansr-ansl ;
    return l<ansl ;
}

main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]) ;
        deque<P> dq ;
        ans=-1 ;
        for(int i=1;i<=n;i++)
        {
            int k=dq.size() , new_num=0 ;
            for(int j=1;j<=k;j++)
            {
                P p=dq.front() ; dq.pop_front() ;
                p.m=min(p.m,a[i]) ; p.sum += a[i] ;
                if(better(p.m*p.sum,p.id,i))
                    {ans=p.m*p.sum ; ansl=p.id ; ansr=i ;}
                while(new_num)
                {
                    P q=dq.back() ;
                    if(q.m*q.sum < p.m*p.sum) {dq.pop_back() ; new_num-- ;}
                    else break ;
                }
                if(!new_num || dq.back().m != p.m)
                    {dq.push_back(p) ; new_num++ ;}
            }
            if(dq.empty() || a[i]!=dq.back().m)
                {dq.push_back((P){a[i],a[i],i}) ;}
        }
        printf("%lld\n%d %d\n\n",ans,ansl,ansr) ;
    }
}
