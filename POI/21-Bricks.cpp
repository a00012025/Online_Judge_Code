#include<bits/stdc++.h>
using namespace std;
const int maxn=1000000+10 ;

int n,k,st,ed ;
int rk[maxn] ;
struct P
{
    int id,num ;
    bool operator < (const P &rhs) const
    {
        if(num!=rhs.num) return num<rhs.num ;
        return rk[id]>rk[rhs.id] ; /// rk[ed]=1
    }
};

int num[maxn] ;
priority_queue<P> pq ;
int ans[maxn] ;

bool solve()
{
    if(!num[st] || !num[ed]) return 0 ;
    if(n==1 && st==ed && num[st]==1) { ans[1]=st ; return 1 ; }
    if(st==ed && num[st]==1) return 0 ;
    num[st]-- ; num[ed]-- ;

    for(int i=1;i<=k;i++) if(i!=st && num[i]) pq.push((P){i,num[i]}) ;

    ans[1]=st ; ans[n]=ed ;
    for(int i=2,now=st;i<=n-1;i++)
    {
        if(pq.empty()) return 0 ;
        P u=pq.top() ; pq.pop() ;
        ans[i]=u.id ;
        num[u.id]-- ;
        if(num[now]) pq.push((P){now,num[now]}) ;
        now=u.id ;
    }
    if(ans[n-1]==ed) return 0 ;
    return 1 ;
}

main()
{
    scanf("%d%d%d",&k,&st,&ed) ;
    for(int i=1;i<=k;i++) scanf("%d",&num[i]) , n+=num[i] ;
    rk[ed]=1 ;
    for(int i=1,j=2;i<=k;i++) if(i!=ed) rk[i]=j++ ;

    if(!solve()) printf("0\n") ;
    else for(int i=1;i<=n;i++) printf("%d%c",ans[i],i==n?'\n':' ') ;
}
