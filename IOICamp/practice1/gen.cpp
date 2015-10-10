#include<bits/stdc++.h>
using namespace std;

int x[100],y[100] ;
main()
{
    srand(time(NULL)) ;
    freopen("in","w",stdout) ;
    int T=100 ; printf("%d\n",T) ;
    while(T--)
    {
        int n=rand()%5+8,m=rand()%5+8,num=(rand()%min(10,m*n-1))+1 ;
        for(int i=1;i<=num;i++) x[i]=rand()%n , y[i]=rand()%m ;
        printf("%d %d\n",n,m) ;
        for(int i=0;i<n;i++) for(int j=0;j<m;j++)
        {
            bool X=0 ;
            for(int k=0;k<num;k++) if(i==x[k]&&j==y[k]) X=1 ;
            printf("%c",X?'X':'.') ;
            if(j==m-1) printf("\n") ;
        }
    }
}
