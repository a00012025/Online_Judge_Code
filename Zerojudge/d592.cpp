#include<bits/stdc++.h>
using namespace std;
const int maxn=1000000+5 ;
struct P
{
    int type,next ;
    bool operator < (const P &rhs) const
    {
        return next < rhs.next ;
    }
};

int a[maxn],last[10001],next[maxn] ;
bool on[10001] ;
main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int n,m ; scanf("%d%d",&n,&m) ;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
        memset(last,0,sizeof(last)) ;
        for(int i=n;i>=1;i--)
        {
            if(last[a[i]]==0) next[i]=n+1 ;
            else next[i]=last[a[i]] ;
            last[a[i]]=i ;
        }
        memset(on,0,sizeof(on)) ;
        int num=0,ans=0 ;
        priority_queue<P> pq ;
        for(int i=1;i<=n;i++)
        {
            if(on[a[i]]) {pq.push((P){a[i],next[i]}) ; continue ;}
            num++ ;
            if(num==m+1)
            {
                P u=pq.top() ; pq.pop() ; //printf("pop %d\n",u.type) ;
                while(!on[u.type]) {u=pq.top() ; pq.pop() ;}
                on[u.type]=0 ; ans++ ;
                num-- ;
            }
            pq.push((P){a[i],next[i]}) ;
            on[a[i]]=1 ;
        }
        printf("%d\n",ans) ;
    }
}
