#include<bits/stdc++.h>
using namespace std;
const int maxn=2000000+10 ;
struct P
{
    int x,y ;
    bool operator < (const P &rhs) const
    {
        if(x!=rhs.x) return x<rhs.x ;
        else return y<rhs.y ;
    }
};

int n ;
int dis(int x,int y)
{
    if(x<=y) return y-x ;
    else return n-x+y ;
}

int a[maxn],b[maxn] ;
set<int> st[maxn] ;
P p[maxn] ;
main()
{
    scanf("%d",&n) ;
    for(int i=0;i<n;i++) scanf("%d",&a[i]) ;
    for(int i=0;i<n;i++) scanf("%d",&b[i]) , st[b[i]].insert(i) ;
    int cnt=0 ;
    for(int i=0;i<n;i++) if(a[i]!=b[i])
    {
        set<int>::iterator it=st[a[i]].lower_bound(i) ;
        int las,nex ;
        if(it==st[a[i]].end()) nex=*(st[a[i]].begin()) ;
        else nex=*it ;
        if(it==st[a[i]].begin()) it=st[a[i]].end() ;
        it-- ; las=*it ;
        p[cnt++]=(P){dis(las,i),dis(i,nex)} ;
    }
    if(cnt==0) {printf("0\n") ; return 0 ;}
    int MX=0 , MY=0 , ans=maxn ;
    priority_queue<P> pq ; int nowmax=0 ;
    for(int i=0;i<cnt;i++) MX=max(MX,p[i].x) , MY=max(MY,p[i].y) , pq.push(p[i]) ;
    ans=min(MX,MY) ;
    while(!pq.empty())
    {
        P u=pq.top() ; pq.pop() ; if(pq.empty()) break ;
        nowmax=max(nowmax,u.y) ;
        if(u.x==pq.top().x) continue ;
        ans=min(ans,min(2*nowmax+pq.top().x,nowmax+2*pq.top().x)) ;
    }
    printf("%d\n",ans) ;
}
