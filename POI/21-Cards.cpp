#include<bits/stdc++.h>
using namespace std;
const int maxn=200000+10 ;

set<int> st[2] ;
int a[maxn],b[maxn] ;

bool check(int x,int y,int t)
{
    if(t==0) return a[y]<a[x] ;
    return b[y]<b[x] ;
}

main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&a[i],&b[i]) ;
        if(a[i]>b[i]) swap(a[i],b[i]) ;
    }
    for(int i=1;i<n;i++)
    {
        if(a[i]>a[i+1]) st[0].insert(i) , printf("st[0]:%d\n",i) ;
        if(b[i]>b[i+1]) st[1].insert(i) , printf("st[1]:%d\n",i) ;
    }

    int Q ; scanf("%d",&Q) ;
    while(Q--)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        if(x>y) swap(x,y) ;
        if(x!=y) for(int t=0;t<2;t++)
        {
            if(x>1 && check(x-1,x,t) && !check(x-1,y,t)) st[t].erase(x-1) ;
            if(x>1 && !check(x-1,x,t) && check(x-1,y,t)) st[t].insert(x-1) ;
            if(check(x,x+1,t) && !check(y,x+1,t)) st[t].erase(x) ;
            if(!check(x,x+1,t) && check(y,x+1,t)) st[t].insert(x) ;
            if(check(y-1,y,t) && !check(y-1,x,t)) st[t].erase(y-1) ;
            if(!check(y-1,y,t) && check(y-1,x,t)) st[t].insert(y-1) ;
            if(y<n && check(y,y+1,t) && !check(x,y+1,t)) st[t].erase(y) ;
            if(y<n && !check(y,y+1,t) && check(x,y+1,t)) st[t].insert(y) ;
        }
        if(st[0].empty() || st[1].upper_bound(*st[0].begin())==st[1].end())
            printf("TAK\n") ;
        else printf("NIE\n") ;
        swap(a[x],a[y]) ; swap(b[x],b[y]) ;
    }
}
