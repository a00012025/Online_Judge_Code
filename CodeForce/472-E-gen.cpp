#include<bits/stdc++.h>
using namespace std;
const int maxn=30 ;

int a[maxn*maxn] ;
main()
{
    freopen("in","w",stdout) ;
    srand(time(NULL)) ;
    int n=rand()%9+2 , m=rand()%9+2 ;
    printf("%d %d\n",n,m) ;

//    for(int i=0;i<n*m;i++) a[i]=i ;
    for(int i=0;i<n*m;i++) a[i]=rand()%900+1 ;

    for(int i=0;i<n;i++) for(int j=0;j<m;j++)
        printf("%d%c",a[i*m+j]+1,j==m-1?'\n':' ') ;
    printf("\n") ;
    random_shuffle(a,a+n*m) ;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++)
        printf("%d%c",a[i*m+j]+1,j==m-1?'\n':' ') ;

}
