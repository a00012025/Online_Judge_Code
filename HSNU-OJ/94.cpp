#define NDEBUG
#ifdef NDEBUG
#define debugf(...) ((void)0)
#else
#define debugf(...) printf(__VA_ARGS__)
#endif // NDEBUG
#include<bits/stdc++.h>
#define LL long long
using namespace std;

int a[100001] ;
main()
{
    int n,M ; LL cost ; scanf("%d%d%lld",&n,&M,&cost) ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
    deque<int> dq1,dq2 ;
    LL sum1=0LL , sum2=0LL ;
    int j=1 , ans=0 ;
    for(int i=1;i<=n;i++)
    {
        debugf("i=%d , j=%d\n",i,j) ;
        while(dq1.size()>=dq2.size()+2)
        {
            int u=dq1.front() ; dq1.pop_front() ; sum1-=(LL)u ;
            dq2.push_back(u) ; sum2+=(LL)u ;
        }
        if(i>1) dq2.pop_front() , sum2-=a[i-1] ;
        while(dq1.size()>=dq2.size()+2)
        {
            int u=dq1.front() ; dq1.pop_front() ; sum1-=(LL)u ;
            dq2.push_back(u) ; sum2+=(LL)u ;
        }
        for(;j<=n;j++)
        {
            dq1.push_back(a[j]) ; sum1+=(LL)a[j] ;
            if(dq1.size()>=dq2.size()+2)
            {
                int u=dq1.front() ; dq1.pop_front() ; sum1-=(LL)u ;
                dq2.push_back(u) ; sum2+=(LL)u ;
            }
            if(j>=2)
            {
                LL mid=(LL)dq1.front() ;
                if(sum1-((LL)dq1.size())*mid -sum2+((LL)dq2.size())*mid > cost)
                {
                    dq1.pop_back() ; sum1-=(LL)a[j] ;
                    break ;
                }
            }
        }
        ans=max(ans,j-i) ;
    }
    printf("%d\n",ans) ;
}
