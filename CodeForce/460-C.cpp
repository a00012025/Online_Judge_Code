#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=100000+10 ;

int a[maxn],n,w ;
struct P{int id ; LL val;};
deque<P> dq ;
LL cal(int x)
{
    dq.clear() ;
    LL sum=0,ret=0 ;
    for(int i=1;i<=n;i++)
    {
        while(!dq.empty() && dq.back().id+w<=i)
            sum-=dq.back().val , dq.pop_back() ;
        LL add=x-a[i]-sum ;
        if(add<=0) continue ;
        ret+=add ; sum+=add ;
        dq.push_front((P){min(i,n-w+1),add}) ;
    }
    return ret ;
}

main()
{
    int m ; scanf("%d%d%d",&n,&m,&w) ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
    int l=1 , r=2e9 ;
    while(r-l>1)
    {
        int mid=l+(r-l)/2 ;
        if(cal(mid)>m) r=mid ;
        else l=mid ;
    }
    printf("%d\n",l) ;
}
