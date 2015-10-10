#include<bits/stdc++.h>
using namespace std;

int l[1000],r[1000] ;
int solve(int n,int m)
{
    if(n==1)
    {
        if(m<=3) return m-1 ;
        if(m%2==0) return 1 ;
        if(m%4==3) return 2 ;
        return 0 ;
    }
    if(n==2) return (m%3==2) ? 4 : 1 ;
    if(n%2) return 0 ;
    if(n==4) return m%5==1 ? 1 : ((m%5==4||m%5==2)?4:0) ;

    if(m%(n+1)==n) return 4 ;
    else if(m%(n+1)==1) return 1 ;
    else if(m%(n+1)==(n-2)) return 1 ;
    return 0 ;
}

main()
{
    int n,m ;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n>m) swap(n,m) ;
        printf("%d\n",solve(n,m)) ;
    }
}
