#include<bits/stdc++.h>
using namespace std;
const int maxn=100+10 ;
char G[maxn][maxn] ;
main()
{
    int n,k ; scanf("%d%d",&n,&k) ;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++)
    {
        G[i][j]='S' ;
        if((i+j)%2==0 && k) G[i][j]='L' , k-- ;
    }
    if(k) printf("NO\n") ;
    else
    {
        printf("YES\n") ;
        for(int i=0;i<n;i++) printf("%s\n",G[i]) ;
    }
}
