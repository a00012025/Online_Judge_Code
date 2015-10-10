#include<bits/stdc++.h>
using namespace std;
struct P{int x,y;}a[100001];
bool cmp(const P &a,const P &b)
{
    if(a.x!=b.x) return a.x<b.x ;
    else return a.y<b.y ;
}

int n ;
bool check()
{
    stack<P> st ; st.push(a[1]) ;
    for(int i=2;i<=n;i++)
    {
        while(!st.empty() && a[i].x>st.top().y) st.pop() ;
        if(!st.empty() && a[i].y>st.top().y) return 0 ;
        st.push(a[i]) ;
    }
    return 1 ;
}
main()
{
    int T; scanf("%d",&T) ;
    while(T--)
    {
        scanf("%d",&n) ;
        for(int i=1;i<=n;i++) scanf("%d%d",&a[i].x,&a[i].y) ;
        sort(a+1,a+n+1,cmp) ;
        if(check()) printf("Y\n") ;
        else printf("N\n") ;
    }
}
