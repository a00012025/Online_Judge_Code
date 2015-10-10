#include<bits/stdc++.h>
using namespace std;

int solve(int *a,int n)
{
    int s=0 ;
    for(int i=1;i<=n;i++) s+=a[i] ;
    for(int i=1,j=0;;i++)
    {
        j+=a[i] ;
        if(2*j>=s) return i ;
    }
}

int x[101],y[101] ;
main()
{
    int n,m ;
    scanf("%d%d",&n,&m) ;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
    {
        int k ; scanf("%d",&k) ;
        x[i]+=k ; y[j]+=k ;
    }
    printf("%d %d\n",solve(x,n),solve(y,m)) ;
}
