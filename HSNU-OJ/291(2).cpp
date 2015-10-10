#include<bits/stdc++.h>
using namespace std;
const int maxn=1000000+10 ;

struct P
{
    int x,y,id ;
    bool operator < (const P &rhs) const
    {
        return y<rhs.y ;
    }
};

bool cmp1(const P &a,const P &b)
{
    return a.x<b.x ;
}

int A,B,n ;
int x[50005],y[50005] ;
P a[maxn] ;

bool check(int num)
{
    priority_queue<P> pq ;
    int j=0 ;
    for(int i=1;i<=A;i++)
    {
        while(j<n && a[j+1].x < x[i]) pq.push(a[++j]) ;
        for(int k=0;k<num && !pq.empty();k++)
            pq.pop() ;
    }
    while(j<n) pq.push(a[++j]) ;
    for(int i=B;i>=1;i--)
    {
//        if(!pq.empty() && pq.top().y >= y[i]) return 0 ;
        for(int k=0;k<num && !pq.empty();k++)
            if(pq.top().y < y[i]) pq.pop() ;
//            pq.pop() ;
            else return 0 ;
    }

    return pq.empty();
}

main()
{
    scanf("%d%d%d",&A,&B,&n) ;
    for(int i=1;i<=A;i++) scanf("%d",&x[i]) ;
    for(int i=1;i<=B;i++) scanf("%d",&y[i]) ;
    for(int i=1;i<=n;i++) scanf("%d%d",&a[i].x,&a[i].y) , a[i].id=i ;
    sort(x+1,x+A+1) ;
    sort(y+1,y+B+1) ;
    sort(a+1,a+n+1,cmp1) ;
    int l=0 , r=n+1 ;
    if(!check(r)) { printf("-1\n") ; return 0 ; }
    while(r-l>1)
    {
        int mid=(r+l)/2 ;
        if(check(mid)) r=mid ;
        else l=mid ;
    }
    printf("%d\n",r) ;
}
