#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=200000+10 ;
int ans[maxn] ;
void solve(int l1,int r1,int l2,int r2,LL k)
{
    if(l1==r1){ans[l1]=l2 ; return ;}
    if(r1-l1<=k) ans[l1]=r2 , solve(l1+1,r1,l2,r2-1,k-r1+l1) ;
    else ans[l1]=l2 , solve(l1+1,r1,l2+1,r2,k) ;
}

main()
{
    int n ; LL k ; scanf("%d%lld",&n,&k) ;
    solve(1,n,1,n,k) ;
    for(int i=1;i<=n;i++) printf("%d%c",ans[i],i==n?'\n':' ') ;
}
