#include<bits/stdc++.h>
using namespace std;
int gcd(int x,int y)
{
    return y==0 ? x : gcd(y,x%y) ;
}
int n,m,g[500][500] ;
main()
{
    for(int i=1;i<=400;i++) for(int j=i;j<=400;j++)
        g[i][j]=g[j][i]=gcd(i,j) ;
    while(scanf("%d%d",&n,&m)==2 && n+m)
    {
        if(n==1 && m==1) {printf("0\n") ; continue ;}
        if(n==1 || m==1) {printf("1\n") ; continue ;}
        int ans=0 ;
        for(int i=1;i<n;i++) for(int j=1;j<m;j++) if(g[i][j]==1)
        {
            int x=max(n-2*i,0)*max(m-2*j,0) ;
            ans+=(n-i)*(m-j)-x ;
        }
        printf("%d\n",2*ans) ;
    }
}
