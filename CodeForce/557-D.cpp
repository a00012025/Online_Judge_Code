#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=100000+10 ;

vector<int> v[maxn] ;
int c[maxn],num1,num2 ;
bool dfs(int x,int col=1)
{
    (col==1 ? num1 : num2)++ ;
    c[x]=col ;
    for(auto i : v[x])
    {
        if(c[i]!=-1 && c[i]==c[x]) return 0 ;
        if(c[i]==-1 && !dfs(i,3-col)) return 0 ;
    }
    return 1 ;
}

main()
{
    int n,m ; scanf("%d%d",&n,&m) ;
    if(!m){printf("3 %I64d\n",(LL)n*(n-1)*(n-2)/6) ; return 0 ;}
    for(int i=0;i<m;i++)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        v[x].push_back(y) ;
        v[y].push_back(x) ;
    }
    memset(c,-1,sizeof(c)) ;
    LL ans=0 ;
    for(int i=1;i<=n;i++) if(c[i]==-1)
    {
        int t1=num1 , t2=num2 ;
        if(!dfs(i)){printf("0 1\n") ; return 0 ;}
        ans+=(LL)(num1-t1)*(num1-t1-1)/2+(LL)(num2-t2)*(num2-t2-1)/2 ;
    }
    if(ans){printf("1 %I64d\n",ans) ; return 0 ;}
    else printf("2 %I64d\n",(LL)m*(n-2)) ; return 0 ;
}
