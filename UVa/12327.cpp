#include<bits/stdc++.h>
#define LL long long
#define F first
#define S second
using namespace std;
const int maxn=20000 ;
map<int,int> mp ;
int n,a[maxn] ;

void dfs(int x,int num,int val)
{
    if(n-x+1 < num) return ;
    if(x==n+1 || !num) { mp[val]++ ; return ; }
    dfs(x+1,num,val) ;
    dfs(x+1,num-1,val+a[x]) ;
}

main()
{
    int T,tc=0 ; scanf("%d",&T) ;
    while(T--)
    {
        int p ; scanf("%d%d",&n,&p) ;
        mp.clear() ;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
        dfs(1,p,0) ;
        printf("Case #%d:\n",++tc) ;
        for(auto i : mp) printf("%d: %d\n",i.F,i.S) ;
        printf("\n") ;
    }
}
