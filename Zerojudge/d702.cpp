#include<stdio.h>
#include<string.h>
long long a[1500][100] ;
main()
{
    memset(a,0,sizeof(a)) ;
    a[1][1]=a[2][1]=a[3][1]=1 ;
    for(int i=4;i<=1000;i++)
    {
        int j ;
        for(j=99;!a[i-2][j];j--) ; j++ ;
        for(int k=1;k<=j;k++)
        {
            a[i][k]+=a[i-2][k]+a[i-3][k] ;
            if(a[i][k]>10000) {a[i][k]-=10000 ; a[i][k+1]++ ;}
        }
    }
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int i ;
        for(i=99;!a[n][i];i--) ;
        printf("%d",a[n][i]) ;
        for(int r=i-1;r>=1;r--) printf("%04d",a[n][r]) ;
        printf("\n") ;
    }
}
