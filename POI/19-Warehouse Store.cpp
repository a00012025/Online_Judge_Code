#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=250000+10 ;

struct P
{
    int id,val ;
    bool operator < (const P &rhs) const
    {
        return val<rhs.val ;
    }
};

priority_queue<P> pq ;
int a[maxn],b[maxn] ;
bool ans[maxn] ;

main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) , ans[i]=1 ;
    for(int i=1;i<=n;i++) scanf("%d",&b[i]) ;
    LL now=0LL ;
    for(int i=1;i<=n;i++)
    {
        now+=a[i]-b[i] ; pq.push((P){i,b[i]}) ;
        if(now<0)
        {
            ans[pq.top().id]=0 ;
            now+=pq.top().val ;
            pq.pop() ;
        }
    }

    int num=count(ans+1,ans+n+1,true) ;
    printf("%d\n",num) ;
    for(int i=1;i<=n;i++) if(ans[i])
        printf("%d%c",i,--num?' ':'\n') ;
}
