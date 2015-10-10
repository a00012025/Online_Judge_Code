#include<bits/stdc++.h>
using namespace std;
const int maxn=100+10 ;

int get2(int x)
{
    for(int i=1;;i++) if(x%i==0)
    {
        int j=x/i ;
        if((i-j)%2==0) return (j-i)/2 ;
    }
}

void get(int *a,int n)
{
    if(n==1) { a[1]=1 ; return ; }
    if(n==2) { a[1]=3 ; a[2]=4 ; return ; }
    for(int i=1;i<=n-1;i++) a[i]=2 ;
    a[n]=get2(4*n-4) ;
}

int a[maxn],b[maxn] ;
main()
{
    int n,m ; scanf("%d%d",&n,&m) ;
    get(a,n) ; get(b,m) ;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
        printf("%d%c",a[i]*b[j],j==m?'\n':' ') ;
}
