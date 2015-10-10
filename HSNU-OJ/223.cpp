#include<bits/stdc++.h>
using namespace std;
const int maxn=300000+10 ;

set<int> st,st2 ;
int now[2*maxn] ;
int n,m,tot ;
int encode(int *a)
{
    int ret=1 ;
    for(int i=0;i<m;i++) ret=ret*n+a[i]-1 ;
    return ret ;
}

bool dfs(int x)
{
    if(x==tot)
    {
        st2.clear() ;
        for(int i=0;i<m-1;i++) now[tot+i]=now[i] ;
        for(int i=tot-m+1;i<tot;i++)
        {
            int val=encode(now+i) ;
            if(st.count(val) || st2.count(val)) return 0 ;
            st2.insert(val) ;
        }
        for(int i=0;i<tot;i++) printf("%d%c",now[i],i==tot-1?'\n':' ') ;
        return 1 ;
    }
    for(int i=1;i<=n;i++)
    {
        now[x]=i ;
        int val=0 ;
        if(x>=m-1)
        {
            val=encode(now+x-m+1) ;
            if(st.count(val)) continue ;
            st.insert(val) ;
        }
        if(dfs(x+1)) return 1 ;
        if(x>=m-1) st.erase(val) ;
    }
    return 0 ;
}

void solve0()
{
    if(m==1)
    {
        for(int i=1;i<=n;i++) printf("%d%c",i,i==n?'\n':' ') ;
        printf("\n") ; return ;
    }
    for(int i=1;i<=n;i++)
    {
        printf("%d",i) ;
        if(i==n) break ;
        printf(" ") ;
        for(int j=i+1;j<=n;j++) printf("%d %d ",i,j) ;
    }
    printf("\n") ;
}
main()
{
//    freopen("in","r",stdin) ;
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        scanf("%d%d",&n,&m) ;
        if(m<=2){solve0() ; continue ;}
        st.clear() ;
        tot=1 ;
        for(int i=1;i<=m;i++) tot*=n ;
        dfs(0) ;
    }
}
