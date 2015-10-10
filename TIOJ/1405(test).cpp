#include<bits/stdc++.h>
using namespace std;

int n=5 , m=5 ;
int a[100],cnt=0 ;
int b[]={0,10,5,4,6,9,1,3,7,8,2} ;
int b2[]={0,1,5,10,4,9,6,3,7,8,2} ;
int b3[]={0,1,5,10,4,9,6,7,3,8,2} ;

void dfs(int l,int r)
{
    if(r==m+n+1)
    {
        bool ok=1 ;
        for(int i=1;i<=m+n;i++) if(a[i]!=b3[i]) ok=0 ;
        if(ok) printf("XDDD\n") ;
        return ;
    }
    int nl= (l==1) ? n : l-1 ;
    int nr= (l==1) ? r+1 : r ;
    swap(a[l],a[r]) ;
    dfs(nl,nr) ;
    swap(a[l],a[r]) ;
    dfs(nl,nr) ;
}

main()
{
    for(int i=1;i<=n+m;i++) a[i]=i ;
    dfs(n,n+1) ;
}
