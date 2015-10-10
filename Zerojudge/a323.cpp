#include<stdio.h>
#include<algorithm>
using namespace std;
main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n) ;
        int i,j ;
        for(i=1;i*i<3*n;i++) ;
        for(j=1;j*(j+1)<n*3;j++) ;
        int ans=min(4*i,4*j+2) ;
        if(n==3) ans=14 ;
        printf("%d\n",ans) ;
    }
}
