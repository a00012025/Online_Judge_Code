#include<bits/stdc++.h>
using namespace std;

int Rand()
{
    return (rand()<<15)+rand() ;
}

main()
{
    freopen("tree","r",stdin) ;
    freopen("in","w",stdout) ;
    srand(time(NULL)) ;
    int n ; scanf("%d",&n) ; printf("%d\n",n) ;
    for(int i=1;i<=n;i++) putchar('a') ; printf("\n") ;
    for(int i=1;i<n;i++)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        printf("%d %d\n",x,y) ;
    }
    int Q=1000000 ; printf("%d\n",Q) ;
    while(Q--)
        printf("%d %d %d %d\n",rand()%n+1,rand()%n+1,rand()%n+1,rand()%n+1) ;
}
