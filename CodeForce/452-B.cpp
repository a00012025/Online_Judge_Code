#include<bits/stdc++.h>
#define DB double
using namespace std;
main()
{
    int n,m ; scanf("%d%d",&n,&m) ;
    if(n==0) printf("0 %d\n0 %d\n0 %d\n0 %d\n",m-1,0,m,1) ;
    else if(m==0) printf("%d 0\n%d 0\n%d 0\n%d 0\n",n-1,0,n,1) ;
    else
    {
        DB d1=sqrt(n*n+m*m)+2*sqrt((n-1)*(n-1)+m*m) ;
        DB d2=sqrt(n*n+m*m)+2*sqrt((m-1)*(m-1)+n*n) ;
        DB d3=2*sqrt(n*n+m*m)+max(n,m) ;
        if(d3>=d1&&d3>=d2)
        {
            printf("0 0\n%d %d\n",n,m) ;
            if(n>=m) printf("0 %d\n%d 0\n",m,n) ;
            else printf("%d 0\n0 %d\n",n,m) ;
        }
        else if(n<=m) printf("%d %d\n0 0\n%d %d\n1 0\n",n-1,m,n,m) ;
        else printf("%d %d\n0 0\n%d %d\n0 1\n",n,m-1,n,m) ;
    }
}
