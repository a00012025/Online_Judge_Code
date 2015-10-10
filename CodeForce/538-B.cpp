#include<bits/stdc++.h>
using namespace std;
const int maxn=20 ;

int a[maxn][maxn] ;
main()
{
    int n ; scanf("%d",&n) ;
    int ma=0 ;
    for(int i=0;n;i++,n/=10)
    {
        int x=n%10 ;
        for(int j=0;j<x;j++) a[j][i]=1 ;
        ma=max(ma,x) ;
    }
    printf("%d\n",ma) ;
    for(int i=0;i<ma;i++)
    {
        int j=maxn-1 ;
        while(!a[i][j]) j-- ;
        while(j>=0) printf("%d",a[i][j]) , j-- ;
        printf("%c",i==ma-1?'\n':' ') ;
    }
}
