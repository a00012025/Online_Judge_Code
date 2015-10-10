#include<bits/stdc++.h>
using namespace std;
const int maxn=10000+10 ;

int a[maxn],cnt ;

void solve(int l,int r)
{
    if(l>r) return ;
    if(l==r) { printf("%d%c",a[l],--cnt?' ':'\n') ; return ; }
    int m=1e10,id ;
    for(int i=l;i<=r;i++) if(a[i]<m) m=a[id=i] ;
    printf("%d%c",a[id],--cnt?' ':'\n') ;
    solve(l,id-1) ; solve(id+1,r) ;
}

main()
{
    int n ;
    while(scanf("%d",&n)==1 && n)
    {
        for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
        cnt=n ;
        solve(1,n) ;
    }
}
