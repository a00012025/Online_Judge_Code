#include<bits/stdc++.h>
#define pii pair<int,int>
#define F first
#define S second
#define mkp(x,y) make_pair(x,y)
using namespace std;
const int maxn=100000+10 ;

pii x[maxn],y[maxn] ;
int n ;
map<int,int> mp ;

bool solve(pii *a)
{
    sort(a+1,a+n+1) ;
    mp.clear() ;
    for(int i=1,j=1;i<=n;i++)
    {
        while(j<=n && a[j].F<=i) mp[a[j].S]++ , j++ ;
        auto it=mp.begin() ;
        if(it->F < i) return 0 ;
        if(!(--it->S)) mp.erase(it) ;
    }
    return 1 ;
}

main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++)
            scanf("%d%d%d%d",&x[i].F,&x[i].S,&y[i].F,&y[i].S) ;
        if(!solve(x) || !solve(y)) printf("NO\n") ;
        else printf("YES\n") ;
    }
}
