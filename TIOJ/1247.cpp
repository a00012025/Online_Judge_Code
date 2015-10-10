#include<bits/stdc++.h>
using namespace std;
const int maxn=10000+10 ;
int n,a[maxn] ;

priority_queue<int> pq ;
int tmp[maxn] ;
bool solve()
{
    while(!pq.empty()) pq.pop() ;
    for(int i=1;i<=n;i++) if(a[i]) pq.push(a[i]) ;
    while(!pq.empty() && pq.top())
    {
        int x=pq.top() ; pq.pop() ;
        for(int i=1;i<=x;i++)
        {
            if(pq.empty()) return 0 ;
            int y=pq.top() ; pq.pop() ;
            if(!y) return 0 ;
            tmp[i]=y-1 ;
        }
        for(int i=1;i<=x;i++) if(tmp[i]) pq.push(tmp[i]) ;
    }
    return 1 ;
}

main()
{
    int tc=0 ;
    while(scanf("%d",&n)==1 && n)
    {
        for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
        if(solve()) printf("Case #%d:Yes\n",++tc) ;
        else printf("Case #%d:No\n",++tc) ;
    }
}
