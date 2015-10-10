#include<bits/stdc++.h>
#include"lib1405.h"
using namespace std;
const int maxn=2000+10 ;

int a[maxn],b[maxn] ; /// b is inv of a
int a0[maxn],b0[maxn] ; /// b0 is inv of a0 , swap a0 -> a
int ans[maxn][maxn] ;
int n,m ;

void SWAP(int x,int y)
{
    ans[y][x-n]=1 ;
    swap(a0[x],a0[y]) ;
    swap(b0[a0[x]],b0[a0[y]]) ;
}

int tmp[maxn] ;
main()
{
    scanf("%d%d",&n,&m) ;
    for(int i=1;i<=n+m;i++)
    {
        int x ; scanf("%d",&x) ;
        if(x<=2*n+m) a[2*n+m+1-x]=i , b[i]=2*n+m+1-x ;
        else a[3*n+2*m+1-x]=i , b[i]=3*n+2*m+1-x ;
    }
    for(int i=1;i<=n+m;i++) { int x ; scanf("%d",&x) ; }
    for(int i=1;i<=n+m;i++) a0[i]=b0[i]=i ;

    for(int i=1;i<=n;i++) if(b[i]<=n && b[i]>i) abort() ;
    for(int i=n+1;i<=n+m;i++) if(b[i]>n && b[i]<i) abort() ;

    for(int i=n+1;i<=n+m;i++)
    {
        if(a0[i]==a[i]) continue ;
        int cnt=0 ;
        for(int j=i; b[a0[j]]<=n && b[a0[j]]>b0[a[i]];j=b[a0[j]])
            tmp[cnt++]=b[a0[j]] ;
        tmp[cnt++]=b0[a[i]] ;
        for(int j=0;j<cnt;j++) SWAP(i,tmp[j]) ;
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
        Report(ans[i][j]) ;
}
